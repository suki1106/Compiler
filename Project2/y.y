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

int result_stmt = 0;

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
            // check expression type
            if($6->d_type != $4) yyerror("type is not compatible");
            //$6->name = *$2;
            Info tmp = *$6;
            tmp.name = *$2;
            tmp.d_type = $4;
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
            Info tmp = Info(*($2), $10,ARRAY_f);
            tmp.size = $8 - $5 +1; // store array size
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
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
            if(result_stmt == 0) yyerror("<ERROR> Function should return value");
            
            result_stmt=0;
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
                Info* id = stb_list.lookup(*$1);
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                if(id->f_type == CONST_f) yyerror("const variable can not be assigned");
                if(sameType(*id,*$3) == 0) yyerror("type is not compatible"); // array?
            }
            | PUT EXPRESSION
            {
                Trace("Find PUT");
            }
            | GET ID
            {
                Trace("Find GET");
                //Symboltable* tb = stb_list.getCurrentTable();
                //int idx=tb->lookup(*$2);
                //if(idx == -1) yyerror("<ERROR> identifier not exists");
                Info* id = stb_list.lookup(*$2);
                if(id == NULL) yyerror("<ERROR> identifier not exists");
                //Info* id = tb->getInfo(idx);
            }
            | RESULT EXPRESSION
            {
                Trace("Find result");
                result_stmt = 1;
                Info* func_info = stb_list.getFunc();
                if(func_info== NULL || func_info->f_type != FUNC_f) yyerror("could't find function declaration");
                if($2->d_type != func_info->d_type)yyerror("function return type is not compatible");
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

EXIT_STMT :  EXIT
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
                //stb_list.dumpCurrentTable();
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type == INT_TYPE){
                        $$ = new Info("",INT_TYPE,CONST_f,($1->i_v+$3->i_v));
                    }else{ 
                        //real type
                        $$ = new Info("",REAL_TYPE,CONST_f,($1->r_v+$3->r_v));
                    }
                }else{
                    $$ = new Info("",$1->d_type,VAR_f);
                }
            }
        |   EXPRESSION '-' EXPRESSION
            {
                Trace("expression - expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type == INT_TYPE){
                        $$ = new Info("",INT_TYPE,CONST_f,($1->i_v-$3->i_v));
                    }else{ 
                        //real type
                        $$ = new Info("",REAL_TYPE,CONST_f,($1->r_v-$3->r_v));
                    }
                }else{
                    $$ = new Info("",$1->d_type,VAR_f);
                }
            }    
        |   EXPRESSION '*' EXPRESSION
            {
                Trace("expression * expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type == INT_TYPE){
                        $$ = new Info("",INT_TYPE,CONST_f,($1->i_v*$3->i_v));
                    }else{ 
                        //real type
                        $$ = new Info("",REAL_TYPE,CONST_f,($1->r_v*$3->r_v));
                    }
                }else{
                    $$ = new Info("",$1->d_type,VAR_f);
                }
            }
        |   EXPRESSION '/' EXPRESSION
            {
                Trace("expression / expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type == INT_TYPE){
                        $$ = new Info("",INT_TYPE,CONST_f,($1->i_v/$3->i_v));
                    }else{ 
                        //real type
                        $$ = new Info("",REAL_TYPE,CONST_f,($1->r_v/$3->r_v));
                    }
                }else{
                    $$ = new Info("",$1->d_type,VAR_f);
                }
            }
        |   '-' EXPRESSION %prec UMINUS
            {
                Trace("- expression");
                if($2->d_type != REAL_TYPE && $2->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($2->f_type == ARRAY_f) yyerror("unary minus is not support array");

                $$ = ($2->d_type == INT_TYPE) ? new Info("",INT_TYPE,$2->f_type,-$2->i_v): new Info("",REAL_TYPE,$2->f_type,-$2->r_v);
            }
        |   EXPRESSION MOD EXPRESSION
            {
                Trace("expression mod expression");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != INT_TYPE) yyerror("Type should be INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    $$ = new Info("",INT_TYPE,CONST_f,($1->i_v%$3->i_v));
                }else{
                    $$ = new Info("",INT_TYPE,VAR_f);
                }
            }
        |   EXPRESSION '>' EXPRESSION
            {
                Trace("EXPRESSION > EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v > $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v > $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION '<' EXPRESSION
            {
                Trace("EXPRESSION < EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v < $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v < $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION '=' EXPRESSION
            {
                Trace("EXPRESSION = EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v == $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v == $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION NE EXPRESSION
            {
                Trace("EXPRESSION != EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v != $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v != $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION LE EXPRESSION
            {
                Trace("EXPRESSION <= EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v <= $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v <= $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION GE EXPRESSION
            {
                Trace("EXPRESSION >= EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != REAL_TYPE && $1->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    if($1->d_type== INT_TYPE){
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->i_v >= $3->i_v));
                    }else{
                        $$ = new Info("",BOOL_TYPE,CONST_f,($1->r_v >= $3->r_v));
                    }
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION AND EXPRESSION
            {
                Trace("EXPRESSION and EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    $$ = new Info("",BOOL_TYPE,CONST_f,$1->b_v && $3->b_v);
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   EXPRESSION OR EXPRESSION
            {
                Trace("EXPRESSION or EXPRESSION");
                if($1->d_type != $3->d_type) yyerror("Type not compatible");
                if($1->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($1->f_type == ARRAY_f || $3->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                if($1->f_type == CONST_f && $3->f_type == CONST_f){
                    $$ = new Info("",BOOL_TYPE,CONST_f,$1->b_v || $3->b_v);
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   NOT EXPRESSION
            {
                Trace("Negation operator");
                if($2->d_type != BOOL_TYPE) yyerror("Type should be BOOLEAN");
                if($2->f_type == ARRAY_f) yyerror("array is not allow to directly perform calculation");
                 if($2->f_type == CONST_f){
                    $$ = new Info("",BOOL_TYPE,CONST_f,!$2->b_v);
                }else{
                    $$ = new Info("",BOOL_TYPE,VAR_f);
                }
            }
        |   '(' EXPRESSION ')'
            {
                $$ = $2;
            }
        |   const_val {Trace("const_value");}
        |   ID 
            {
                //Symboltable* tb = stb_list.getCurrentTable(); 
                //int idx = tb->lookup(*$1);
                //if(idx == -1) yyerror("ID not exists");
                //$$ = tb->getInfo(idx);
                Info* id = stb_list.lookup(*$1);
                if(id == NULL) yyerror("ID not exists");
                $$ = id;           
            }
        |   ID'['EXPRESSION']'
            {
                Trace("Array reference");
                //check expression type
                if($3->d_type != INT_TYPE)yyerror("expression should be INT_EXPR");
                if($3->f_type == FUNC_f || $3->f_type== ARRAY_f)yyerror("can not pass Array or Function id");
                $$ = new Info("",$3->d_type,VAR_f);
            }
        |   func_inv
        ;   

func_inv: ID '('actual_params')'
        {
            Trace("function invocation");
            //Symboltable* tb =stb_list.getCurrentTable();
            //int idx= tb->lookup(*$1);
            //if(idx==-1)yyerror("identifier not exists");
            //Info* func_info = tb->getInfo(idx);
            
            Info* func_info = stb_list.lookup(*$1);
            if(func_info == NULL)yyerror("function not exists");
            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");
            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }
            params.clear();
            $$ = new Info("",func_info->d_type,VAR_f);
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


conditional_stmt:   IF{stb_list.create_table();} EXPRESSION THEN func_stmts ELSE_stmt
                    {
                        if($3->d_type != BOOL_TYPE) yyerror("condition should be bool_expr");
                    }
                ;

ELSE_stmt: ELSE{stb_list.popTable();stb_list.create_table();} func_stmts END IF {Trace("if-ELSE stmt");stb_list.popTable();}
        | END IF {Trace("if stmt");stb_list.popTable();}
        ;

loop_stmt: LOOP 
            {
                stb_list.create_table();
            }func_stmts END LOOP
            {
                Trace("loop");
                stb_list.popTable();
            }
        |   FOR opt_r ID':' EXPRESSION'.''.'EXPRESSION 
            {
                if($5->f_type != CONST_f || $8->f_type != CONST_f) yyerror("form should be <for identifier : const_expr .. const_expr>");
                stb_list.create_table();
            }func_stmts END FOR
            {
                Trace("For loop");
                stb_list.popTable();
            }
        ;

opt_r: DECREASING
        | 
        ;




%%


void yyerror(string msg)
{
    cerr << "line: " << linenum << " " <<msg << endl;
    //exit(1);
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