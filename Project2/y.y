%{
#include <stdio.h>
#include <string>
#include <iostream>

#include "symbols.hpp"
#include "lex.yy.cpp"


using namespace std;

void yyerror(string s);
#define Trace(t)        printf("%s\n",t);
Symboltable tb;
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
%type <Inf> EXPRESSION const_val


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
            $4->name = *$2;
            if(tb.Insert(*($4)) ==-1)yyerror("<ERROR> identifier already exists");
            

            //tb.dump();
        }
        | CONST ID ':'TYPE AS EXPRESSION
        {
            Trace("constant declaration with type declaration");
            if($6->f_type != CONST_f) yyerror("<ERROR> expression should be constant");
            $6->name = *$2;
            if(tb.Insert(*($6)) ==-1)yyerror("<ERROR> identifier already exists");

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
            if(tb.Insert(Info(*($2),$4,VAR_f))  == -1) yyerror("<ERROR> identifier already exists"); 
        }
        | VAR ID ':'TYPE AS EXPRESSION
        {
            Trace("variable declaration with value initialization and type");
            $6->name = *$2;
            if($6->d_type != $4)  yyerror("<ERROR> Type not compatible");
            if(tb.Insert(*($6))  == -1) yyerror("<ERROR> identifier already exists");

        }
        | VAR ID AS EXPRESSION
        {
            Trace("variable declaration iwth value initialization but not type");
            $4->name = *$2;
            if(tb.Insert(*$4) == -1)yyerror("<ERROR> identifier already exists");
        }   
        | VAR ID ':' ARRAY val_INTEGER '.''.' val_INTEGER OF TYPE
        {
            Trace("Array declaration");
            if(tb.Insert(Info(*($2), $10,ARRAY_f)) == -1)yyerror("<ERROR> identifier already exists");
        }
        ;

func_dec: FUNCTION ID '('args')'':'TYPE func_stmts END ID
        {

            Trace("Func declaration");
        }
        | PROCEDURE ID '('args')' func_stmts END ID
        {
            Trace("procedure declaration");
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
    ;



stmt:  BLOCK_stmt
    |   simple_stmt
    |   conditional_stmt
    |   loop_stmt

BLOCK_stmt: BEG func_stmts END
        {
            // new symbol table
            Trace("find block");
        }
        ;


simple_stmt: ID AS EXPRESSION /* check const */
            {
                Trace("Assign value to ID");
            }
            | PUT EXPRESSION
            {
                Trace("Find PUT");
            }
            | GET ID
            {
                Trace("Find GET");
            }
            | RESULT EXPRESSION
            {
                Trace("Find result");
            }
            | RETURN
            {
                Trace("Find RETURN");
            }
            | EXIT_STMT
            {
                
            }
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
                Trace("Find EXIT with boolean expression");
            }
            ;

EXPRESSION: EXPRESSION '+' EXPRESSION
            {
                Trace("expression + expression");
            }
        |   EXPRESSION '-' EXPRESSION
            {
                Trace("expression - expression");
            }    
        |   EXPRESSION '*' EXPRESSION
            {
                 Trace("expression * expression");
            }
        |   EXPRESSION '/' EXPRESSION
            {
                Trace("expression / expression");
            }
        |   '-' EXPRESSION %prec UMINUS
            {
                Trace("- expression");
            }
        |   EXPRESSION MOD EXPRESSION
            {
                Trace("expression mod expression");
            }
        |   EXPRESSION '>' EXPRESSION
            {
                Trace("EXPRESSION > EXPRESSION");
            }
        |   EXPRESSION '<' EXPRESSION
            {
                Trace("EXPRESSION < EXPRESSION");
            }
        |   EXPRESSION '=' EXPRESSION
            {
                Trace("EXPRESSION = EXPRESSION");
            }
        |   EXPRESSION NE EXPRESSION
            {
                Trace("EXPRESSION != EXPRESSION");
            }
        |   EXPRESSION LE EXPRESSION
            {
                Trace("EXPRESSION <= EXPRESSION");
            }
        |   EXPRESSION GE EXPRESSION
            {
                Trace("EXPRESSION >= EXPRESSION");
            }
        |   EXPRESSION AND EXPRESSION
            {
                Trace("EXPRESSION and EXPRESSION");
            }
        |   EXPRESSION OR EXPRESSION
            {
                Trace("EXPRESSION or EXPRESSION");
            }
        |   NOT EXPRESSION
            {
                Trace("Negation operator");
            }
        |   '(' EXPRESSION ')'
            {
                $$ = $2;
            }
        |   const_val {Trace("const_value");}
        |   ID 
        |   ID'['EXPRESSION']'
            {
                Trace("Array reference");
                //check expression type
            }
        |   proc_inv
            {

            }
        ;   

proc_inv:;

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
    cerr << msg << endl;
    exit(1);
}

int main()
{
    yyparse();
    tb.dump();
    return 0;
}


int yywrap()
{
    return 1;
}