%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

#include "symbols.hpp"
#include "lex.yy.cpp"


using namespace std;

void yyerror(string s);
#define Trace(t)        printf("%s\n",t);


vector<arg_info> args_info;
vector<Info> params; // deal with function invocation
Symboltable_List stb_list;

%}

%union{
    int i_v;
    bool b_v;
    string* s_v;
    double r_v;
    data_type d_t;
    Info* Inf;
}

%token AS 
%token VAR CONST FUNCTION
%token BOOL REAL INT STRING ARRAY OF CHAR


%token MOD AND OR NOT
%token DECREASING DEFAULT DO ELSE END EXIT FOR GET IF LOOP PUT PROCEDURE RESULT
%token RETURN SKIP THEN WHEN BEG
%token LE GE NE

%token <s_v> ID
%token <s_v>val_STR
%token <i_v>val_INTEGER
%token <r_v>val_REAL
%token <b_v>val_BOOL

%type <d_t> TYPE
%type <Inf> EXPRESSION const_val func_inv

%left OR
%left AND
%left NOT
%left '<' LE '=' GE '>' NE
%left '-' '+'
%left '*' '/' MOD
%nonassoc UMINUS 


%%
program:    dec_stmts stmts;

dec_stmts:  dec_stmt dec_stmts
        | 
        ;
        
stmts:  stmt stmts
        | 
        ;

/* variable, constant, or function */
dec_stmt: var_dec
        | const_dec
        | func_dec
        ;

const_dec:  CONST ID AS EXPRESSION
        {
            Trace("constant declaration without type declaration");
            if($4->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            //$4->name = *$2;
            Info tmp = *$4;
            tmp.name = *$2;

            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            //tb.dump();
        }
        | CONST ID ':'TYPE AS EXPRESSION
        {
            Trace("constant declaration with type declaration");
            if($6->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            //$6->name = *$2;
            Info tmp = *$6;
            tmp.name = *$2;
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            //tb.dump();
        }
        ;

const_val: val_REAL {$$ = new Info("",REAL_TYPE,CONST_f,$1);}
        | val_INTEGER {$$= new Info("",INT_TYPE,CONST_f,$1);}
        | val_STR {$$=new Info("",STR_TYPE,CONST_f,$1);}
        | val_BOOL {$$=new Info("",BOOL_TYPE,CONST_f,$1);}
        ;



/* value*/
/*const_exp or not const_exp*/
/* int, bool , string, real*/


TYPE: INT {$$ = INT_TYPE;}
    | BOOL  {$$ = BOOL_TYPE;}
    | STRING {$$=STR_TYPE;}
    | REAL  {$$=REAL_TYPE;}
    ;



var_dec: VAR ID ':'TYPE
        {
            Trace("variable declaration without value initialization");
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*($2),$4,VAR_f))  == -1) yyerror("<ERROR> identifier already exists"); 
        }
        | VAR ID ':'TYPE AS EXPRESSION
        {
            Trace("variable declaration with value initialization and type");
            //$6->name = *$2;
            //$6->f_type = VAR_f;

            Info tmp = *$6;
            if(tmp.d_type != $4)  yyerror("<ERROR> Type not compatible");
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            Symboltable* tb = stb_list.getCurrentTable();
            tmp.name = *$2;
            tmp.f_type = VAR_f;
            if(tb->Insert(tmp)  == -1) yyerror("<ERROR> identifier already exists");
        }
        | VAR ID AS EXPRESSION
        {
            Trace("variable declaration iwth value initialization but not type");
            //$4->name = *$2;
            //$4->f_type = VAR_f;
            Info tmp = *$4;
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            tmp.name = *$2;
            tmp.f_type = VAR_f;
            
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
        }   
        | VAR ID ':' ARRAY val_INTEGER '.''.' val_INTEGER OF TYPE
        {
            Trace("Array declaration");
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*($2), $10,ARRAY_f)) == -1)yyerror("<ERROR> identifier already exists");
        }
        ;

func_dec: FUNCTION ID '('args')'':'TYPE
        {
            //if(*$2 != *$11) yyerror("<ERROR> Func declaration error");

            Trace("Func declaration");

            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(Info(*$2,$7,FUNC_f,args_info) ) ==-1)yyerror("<ERROR> identifier already exists");
            
            // create new symbol table and switch
            stb_list.create_table();
            tb = stb_list.getCurrentTable(); // copy constructor?
            for(auto& arg:args_info)
                tb->Insert(Info(arg.name,arg.d_type,VAR_f)); // insert arg into table
            
            //tb->printTableSize();
            args_info.clear();
        } 
        func_stmts END ID
        {
            if(*$2 != *$11) yyerror("<ERROR> Func declaration error");
            //check result expression ?

            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
        | PROCEDURE ID '('args')' 
        {
            Trace("procedure declaration");
            // new symbol table
            Symboltable* tb = stb_list.getCurrentTable();
            if( tb->Insert(Info(*$2,VOID_TYPE,FUNC_f,args_info)) ==-1) yyerror("<ERROR> identifier already exists");
            
            //create new table and switch, store args info in new table
            stb_list.create_table();
            tb = stb_list.getCurrentTable();
            for(auto& arg:args_info)
                tb->Insert(Info(arg.name,arg.d_type,VAR_f)); // store parameter info     
            //tb->printTableSize();
            args_info.clear();
        }func_stmts END ID
        {
            if(*$2 != *$9) yyerror("<ERROR> Procedure declaration error");
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
        ;


func_stmts: func_stmt func_stmts
            |
            ;


/* without function declaration */
func_stmt: var_dec
        |  const_dec
        |  stmt
        ;

args: arg ',' args
    | arg
    | 
    ;
    
arg: ID':'TYPE  
    {
        args_info.push_back(arg_info(*$1,$3));
    }
    ;



stmt:  BLOCK_stmt
    |   simple_stmt
    |   conditional_stmt
    |   loop_stmt

BLOCK_stmt: BEG
        {
            stb_list.create_table();
        } func_stmts END{
            Trace("find block stmt");
            // BLOCK ends, call popTable
            stb_list.dumpCurrentTable();
            stb_list.popTable();
        }
        ;


simple_stmt: ID AS EXPRESSION 
            {
                Trace("Assign value to ID");
                /* EXPRESSION only allow CONST? */
                /* check ID const or not*/
                Symboltable* tb = stb_list.getCurrentTable();
                int idx=tb->lookup(*$1);
                if(idx == -1) yyerror("<ERROR> identifier not exists");
                Info* id = tb->getInfo(idx);
                if(id->f_type == CONST_f) yyerror("const variable can not be assigned");
                if(id->d_type != $3->d_type) yyerror("type is not compatible");
            }
            | PUT EXPRESSION
            {
                Trace("Find PUT");
            }
            | GET ID
            {
                Trace("Find GET");
                Symboltable* tb = stb_list.getCurrentTable();
                int idx=tb->lookup(*$2);
                if(idx == -1) yyerror("<ERROR> identifier not exists");
                //Info* id = tb->getInfo(idx);
            }
            | RESULT EXPRESSION
            {
                Trace("Find result");
                // check function type
            }
            | RETURN
            {
                Trace("Find RETURN");
            }
            | EXIT_STMT
            | SKIP
            {
                Trace("Find skip");
            }
            ;

EXIT_STMT : EXIT
            {
                Trace("Find EXIT");
            }
            | EXIT WHEN EXPRESSION
            {
                Trace("Find EXIT with expression");
                if($3->d_type != BOOL_TYPE)yyerror("<ERROR> EXIT WHEN EXPRESSION, EXPRESSION SHOULD BE BOOL_EXPR");

            }
            ;

EXPRESSION: EXPRESSION '+' EXPRESSION
            {
                Trace("expression + expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    
                }
            }
        |   EXPRESSION '-' EXPRESSION
            {
                Trace("expression - expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }    
        |   EXPRESSION '*' EXPRESSION
            {
                Trace("expression * expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION '/' EXPRESSION
            {
                Trace("expression / expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   '-' EXPRESSION %prec UMINUS
            {
                Trace("- expression");
                if($2->d_type != REAL_TYPE || $2->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($2->f_type == ARRAY_f) yyerror("unary minus is not support array");
            }
        |   EXPRESSION MOD EXPRESSION
            {
                Trace("expression mod expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION '>' EXPRESSION
            {
                Trace("EXPRESSION > EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION '<' EXPRESSION
            {
                Trace("EXPRESSION < EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION '=' EXPRESSION
            {
                Trace("EXPRESSION = EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION NE EXPRESSION
            {
                Trace("EXPRESSION != EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION LE EXPRESSION
            {
                Trace("EXPRESSION <= EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION GE EXPRESSION
            {
                Trace("EXPRESSION >= EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE || $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION AND EXPRESSION
            {
                Trace("EXPRESSION and EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   EXPRESSION OR EXPRESSION
            {
                Trace("EXPRESSION or EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   NOT EXPRESSION
            {
                Trace("Negation operator");
                if($2->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($2->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
            }
        |   '(' EXPRESSION ')'
            {
                $$ = $2;
            }
        |   const_val {Trace("const_value");}
        |   ID 
            {
                Symboltable* tb = stb_list.getCurrentTable(); 
                int idx = tb->lookup(*$1);
                if(idx == -1) yyerror("ID not exists");
                $$ = tb->getInfo(idx);               
            }
        |   ID'['EXPRESSION']'
            {
                Trace("Array reference");
                //check expression type
                if($3->d_type != INT_TYPE)yyerror("expression should be INT_EXPR");
                if($3->f_type == FUNC_f || $3->f_type== ARRAY_f)yyerror("can not pass Array or Function id");
            }
        |   func_inv
        ;   

func_inv: ID '('actual_params')'
        {
            Trace("function invocation");
            Symboltable* tb =stb_list.getCurrentTable();
            int idx= tb->lookup(*$1);
            if(idx==-1)yyerror("identifier not exists");
            Info* func_info = tb->getInfo(idx);
            
            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");

            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }

            params.clear();

            
        }
        ;

actual_params: actual_param ',' actual_params
            | actual_param
            |
            ;

actual_param: EXPRESSION
            {
                params.push_back(*$1);
            }
            ;

conditional_stmt: IF EXPRESSION THEN func_stmts ELSE func_stmts END IF
                    {
                        Trace("if-ELSE stmt");
                    }
                |  IF EXPRESSION THEN func_stmts END IF
                    {
                        Trace("if stmt");
                    }
                ;
                    


                

loop_stmt: LOOP func_stmts END LOOP
            {
                Trace("loop");
            }
        |   FOR opt_r ID':' val_INTEGER'.''.'val_INTEGER func_stmts END FOR
            {
                Trace("For loop");
            }
        ;

opt_r: DECREASING
        | 
        ;




%%


void yyerror(string msg)
{
    cerr << "line: " << linenum << " " <<msg << endl;
    exit(1);
}

int main()
{
    yyparse();
    stb_list.dumpAllTable();
    return 0;
}


int yywrap()
{
    return 1;
}