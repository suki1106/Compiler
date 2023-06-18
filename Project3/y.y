%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <fstream>

#include "symbols.hpp"
#include "lex.yy.cpp"


using namespace std;

void yyerror(string s);
#define Trace(t)        printf("%s\n",t);

string out_name;
ofstream out_f;

vector<arg_info> args_info;
vector<Info> params; // deal with function invocation
Symboltable_List stb_list;

int result_stmt = 0;

int counter_local_var = 0; // for project3
int label_index=0;
stack<int> st_label;

//int label_used=0;




bool isConst_Exp = 0;


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
program:   
        {
            out_f << "class " << out_name.substr(0,out_name.find(".")) << "\n{\n";
        }
        dec_stmts 
        {
            // enter main block
            out_f << "\tmethod public static void main(java.lang.String[])\n";
            out_f << "\tmax_stack 15\n";
            out_f << "\tmax_locals 15\n";
            out_f << "\t{\n";

        }
        stmts
        {
            out_f << "\t\treturn\n";
            out_f << "\t}\n";
            out_f << "}";
            out_f.close();
        }

        ;

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

const_dec:  CONST ID AS{isConst_Exp=1;} EXPRESSION
        {
            Trace("constant declaration without type declaration");
            if($5->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            //$4->name = *$2;
            Info tmp = *$5;
            tmp.name = *$2;
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            isConst_Exp=0;
            //tb.dump();
        }
        | CONST ID ':'TYPE AS{isConst_Exp=1;} EXPRESSION
        {
            Trace("constant declaration with type declaration");
            if($7->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            // check expression type
            if($7->d_type != $4) yyerror("type is not compatible");
            //$6->name = *$2;
            Info tmp = *$7;
            tmp.name = *$2;
            tmp.d_type = $4;
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) ==-1)yyerror("<ERROR> identifier already exists");
            isConst_Exp=0;
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
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType($4) << " " << *$2 << "\n"; // global
            }else{
                Info* data = tb->getInfo(tb->lookup(*$2));
                data->index_local = counter_local_var++;
            }
        }
        | VAR ID ':'TYPE AS{isConst_Exp=1;} EXPRESSION
        {
            Trace("variable declaration with value initialization and type");
            isConst_Exp=0;
            Info tmp = *$7;
            if(tmp.d_type != $4)  yyerror("<ERROR> Type not compatible");
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            Symboltable* tb = stb_list.getCurrentTable();
            tmp.name = *$2;
            tmp.f_type = VAR_f;
            if(tb->Insert(tmp)  == -1) yyerror("<ERROR> identifier already exists");
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType($4) << " " << *$2 << " = " << getValue_IntBool(tmp) <<"\n";
            }else{
                Info* data = tb->getInfo(tb->lookup(*$2));
                data->index_local = counter_local_var;
                out_f << "\t\t" << "sipush " << getValue_IntBool(*data) <<"\n";
                out_f << "\t\t" << "istore " << counter_local_var << "\n";
                ++counter_local_var;
            }
        }
        | VAR ID AS{isConst_Exp=1;} EXPRESSION
        {
            Trace("variable declaration iwth value initialization but not type");
            isConst_Exp=0;
            //$4->name = *$2;
            //$4->f_type = VAR_f;
            Info tmp = *$5;
            if(tmp.f_type != CONST_f) yyerror("<ERROR> expression should be constant_expr");
            tmp.name = *$2;
            tmp.f_type = VAR_f;
            
            Symboltable* tb = stb_list.getCurrentTable();
            if(tb->Insert(tmp) == -1)yyerror("<ERROR> identifier already exists");
            if(stb_list.isGlobal()){
                out_f << "\t" << "field static " << getType(tmp.d_type) << " " << *$2 << " = " << getValue_IntBool(tmp) <<"\n";
            }else{
                Info* data = tb->getInfo(tb->lookup(*$2));
                data->index_local = counter_local_var;
                out_f << "\t\t" << "sipush " << getValue_IntBool(*data) <<"\n";
                out_f << "\t\t" << "istore " << counter_local_var << "\n";
                ++counter_local_var;
            }
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
                if(id->isGlobalVar == 1){
                    out_f << "putstatic " << getType(id->d_type) << " " << out_name.substr(0,out_name.find(".")) + "." + id->name << "\n";
                }else{
                    out_f << "istore " << id->index_local << "\n";
                }
            }
            | PUT
            {
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
            } EXPRESSION
            {
                Trace("Find PUT");
                if($3->d_type ==INT_TYPE || $3->d_type == BOOL_TYPE){
                    out_f << "invokevirtual void java.io.PrintStream.print(int)\n";
                }else{ // string
                    out_f << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                }
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
                out_f << "getstatic java.io.PrintStream java.lang.System.out\n";
                out_f << "invokevirtual void java.io.PrintStream.println()\n";
            }
            | proc_inv
            ;

EXIT_STMT :  EXIT
            {
                Trace("Find EXIT");
            }
            | EXIT WHEN EXPRESSION
            {
                Trace("Find EXIT with expression");
                if($3->d_type != BOOL_TYPE)yyerror("<ERROR> EXIT WHEN EXPRESSION, EXPRESSION SHOULD BE BOOL_EXPR");

                int index=st_label.top();
                out_f << "ifne L" << index+1 << "\n";


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
                if(!isConst_Exp)out_f << "iadd\n";
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
                if(!isConst_Exp)out_f << "isub\n";
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
                if(!isConst_Exp)out_f << "imul\n";
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
                if(!isConst_Exp)out_f << "idiv\n";
            }
        |   '-' EXPRESSION %prec UMINUS
            {
                Trace("- expression");
                if($2->d_type != REAL_TYPE && $2->d_type != INT_TYPE) yyerror("Type should be REAL/INT");
                if($2->f_type == ARRAY_f) yyerror("unary minus is not support array");

                $$ = ($2->d_type == INT_TYPE) ? new Info("",INT_TYPE,$2->f_type,-$2->i_v): new Info("",REAL_TYPE,$2->f_type,-$2->r_v);
                if(!isConst_Exp)out_f << "ineg\n";
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

                if(!isConst_Exp)out_f << "irem\n";
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


                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifgt L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "iflt L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifeq L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifne L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifle L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                if(!isConst_Exp){
                    out_f << "isub\n";
                    out_f << "ifge L" << label_index << "\n";
                    out_f << "iconst_0" << "\n";
                    out_f << "goto L" << label_index+1 << "\n";
                    out_f << "L" << label_index << ": iconst_1\n";
                    out_f << "L" << label_index+1 << ":\n";
                    label_index+=2;
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
                
                if(!isConst_Exp)out_f << "iand\n";

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
                if(!isConst_Exp)out_f << "ior\n";
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
                if(!isConst_Exp)out_f << "ixor\n";
            }
        |   '(' EXPRESSION ')'
            {
                $$ = $2;
            }
        |   const_val 
            {
                Trace("const_value");
                // what if const variable declaration?
                if(!isConst_Exp){
                    switch($1->d_type){
                        case INT_TYPE:
                            out_f << "\t\t" << "sipush " << getValue_IntBool(*$1) << "\n";
                            break;
                        case STR_TYPE:
                            out_f << "\t\t" << "ldc " <<"\"" +*($1->s_v)+"\"" << "\n";
                            break;
                        case BOOL_TYPE:
                            out_f << "\t\t" << "iconst_" << getValue_IntBool(*$1) << "\n";
                            break;
                        default:
                            cout << "Not support for real type" << endl;
                            exit(1);
                    }
                }
            }
        |   ID 
            {
                Info* id = stb_list.lookup(*$1);
                if(id == NULL) yyerror("ID not exists");
                if(id->f_type == FUNC_f) yyerror("func invocation error");
                $$ = id;           
                
                if(id->f_type == CONST_f){
                    // iconst_value for bool
                    // sipush for int
                    // ldc for string
                    switch(id->d_type){
                        case INT_TYPE:
                            out_f << "\t\t" << "sipush " << getValue_IntBool(*id) << "\n";
                            break;
                        case STR_TYPE:
                            out_f << "\t\t" << "ldc " <<"\"" +*(id->s_v)+"\"" << "\n";
                            break;
                        case BOOL_TYPE:
                            out_f << "\t\t" << "iconst_" << getValue_IntBool(*id) << "\n";
                            break;
                        default:
                            cout << "Not support for real type" << endl;
                            exit(1);
                    }
                }else{
                    if(id->isGlobalVar == 1){
                        string tmp = out_name.substr(0,out_name.find(".")) + "." + id->name; // example.a
                        out_f << "\t\t" << "getstatic " << getType(id->d_type) << " " << tmp << "\n";
                    }else{
                        int local_var_number = id->index_local;
                        out_f << "\t\t" << "iload " << local_var_number << "\n";
                    }
                }
            }
        |   ID'['EXPRESSION']'
            {
                Trace("Array reference");
                //check expression type
                Info* id = stb_list.lookup(*$1);
                if(id == NULL) yyerror("ID not exists");
                if($3->d_type != INT_TYPE)yyerror("expression should be INT_EXPR");
                if($3->f_type == FUNC_f || $3->f_type== ARRAY_f)yyerror("can not pass Array or Function id");
                $$ = new Info("",id->d_type,VAR_f);
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
            // can not be procedure

            if(func_info->d_type == VOID_TYPE) yyerror("<ERROR> expression is not available for procedure");

            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");
            
            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }
            params.clear();
            $$ = new Info("",func_info->d_type,VAR_f);
        }
        ;


proc_inv: ID '('actual_params')'
        {
            Trace("procedure invocation");

            
            Info* func_info = stb_list.lookup(*$1);
            if(func_info == NULL)yyerror("procedure not exists");

            if(func_info->d_type != VOID_TYPE) yyerror("<ERROR> simple statments is not support for function ");

            if(params.size() != func_info->params.size())yyerror("number of parameters are not the same");
            
            // compare type

            for(int i = 0 ;i <params.size();i++){
                if(params[i].d_type != func_info->params[i].d_type) yyerror("<ERROR>type is different");
            }
            params.clear();
            //$$ = new Info("",func_info->d_type,VAR_f);
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


conditional_stmt:   IF EXPRESSION THEN
                    {                    
                        stb_list.create_table();
                        // jump to L0
                        //label_temp = label_index;

                        st_label.push(label_index);
                        out_f << "ifeq L" << label_index << "\n";
                        label_index+=2;


                        //label_max_tmp = max(label_index,label_max_tmp);
                    }
                    func_stmts ELSE_stmt
                    {
                        // jump to L1 ? (Lexit)
                        // if stmt (Lexit = L0)
                        // if-else (Lexit != L0)
                        if($2->d_type != BOOL_TYPE) yyerror("condition should be bool_expr");
                    }
                ;

ELSE_stmt: ELSE
        {
            stb_list.popTable();
            stb_list.create_table();
            //jump to lexit
            
            int index = st_label.top();
            //int base = label_index - (label_used);
            out_f << "goto L" << index+1 << "\n";
            out_f << "L" << index <<":\n";
        
        } func_stmts END IF 
        {
            Trace("if-ELSE stmt");
            stb_list.popTable();
            
            //int base = label_index - (label_used);
            
            int index = st_label.top();
            out_f << "L" << index+1 << ":\n";
            
            st_label.pop();
         
        }
        | END IF 
        {
            Trace("if stmt");
            stb_list.popTable();

            //int base = label_index - (label_used);

            int index = st_label.top();
            out_f << "L" << index << ":\n";

            st_label.pop();

            //label_index += 1; // should be modified (due to Nested if)
            
            //label_index-=2;
           
        }
        ;

loop_stmt: LOOP 
            {
                stb_list.create_table();
                st_label.push(label_index);
                out_f << "L" << label_index <<":" << "\n"; // begin
                label_index+=2;
            }func_stmts 
            {
                int index= st_label.top();
                out_f << "goto L" << index  << "\n";
            }
            END LOOP
            {
                Trace("loop");
                stb_list.popTable();
                int index= st_label.top();
                out_f << "L" << index+1 << ":" << "\n";
                st_label.pop();
            }
        |   FOR opt_r ID':' EXPRESSION'.''.'EXPRESSION 
            {
                Info* id = stb_list.lookup(*$3);
                if(id==NULL)yyerror("<ERROR> can't find identifier definition");
                if($5->f_type != CONST_f || $8->f_type != CONST_f) yyerror("form should be <for identifier : const_expr .. const_expr>");
                stb_list.create_table();
                
                // decreasing index check?

                out_f << "sipush " << getValue_IntBool(*$5) << "\n";
                out_f << "istore " << id->index_local << "\n";

                st_label.push(label_index);

                out_f << "L" << label_index << ":\n";
                out_f << "iload " << id->index_local << "\n";
                out_f << "sipush " << getValue_IntBool(*$8) << "\n";
                out_f << "isub\n";
                out_f << "ifgt L" << label_index+1 << "\n"; // for increasing, decreasing(iflt)


                label_index+=2;
            }func_stmts 
            {
                Info* id = stb_list.lookup(*$3);
                int index= st_label.top();
                out_f << "iload " << id->index_local << "\n";
                out_f << "sipush 1" << "\n"; // increase 1
                out_f << "iadd\n";
                out_f << "istore " << id->index_local << "\n";
                out_f << "goto L" << index << "\n";
            }
            END FOR
            {
                Trace("For loop");
                stb_list.popTable();
                int index= st_label.top();

                st_label.pop();
                out_f << "L" << index+1 << ":\n";
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

int main(int argc , char*argv[])
{
    if(argc!=2){
        cout << "<ERROR> Usage: ./parser your_st_program.st" << endl;
        exit(1);
    }

    yyin = fopen(argv[1],"r");

    if(yyin == NULL){
        cout << "file \"" << argv[1] << "\" not exist" << endl;
        exit(1);
    }


    out_name = string(argv[1]);

    std::size_t dot_pos = out_name.find('.');

    if(dot_pos != string::npos && out_name.substr(dot_pos) == ".st"){
        out_name = out_name.replace(dot_pos+1,2,"jasm");
        
        out_f.open(out_name);
        if(!out_f.is_open()){
            cout << "unable to write file";
            exit(1);
        }
    }else{
        cout << "this is only support for simple turing Programming Language" << endl;
        exit(1);
    }



    yyparse();
    stb_list.dumpAllTable();

    return 0;
}


int yywrap()
{
    return 1;
}