%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "y.tab.hpp"


#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n", #t); }
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}

#define MAX_LINE_LENG 256



int linenum = 1;
char buf[MAX_LINE_LENG];
char strbuf[MAX_LINE_LENG];



%}

LETTER [A-Za-z]
DIGIT [0-9]
DIGITS {DIGIT}+
INTEGER {DIGITS}
REAL {DIGITS}("."{DIGITS})
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
WHITESPACE [ \t]+



%x COMMENT
%x STR


%%

"." {token('.'); return yytext[0];}
"," {token(','); return yytext[0];}
":" {token(":"); return yytext[0];}
";" {token(";"); return yytext[0];}
"(" {token('('); return yytext[0];}
")" {token(')'); return yytext[0];}
"[" {token('['); return yytext[0];}
"]" {token(']'); return yytext[0];}
"{" {token('{'); return yytext[0];}
"}" {token('}'); return yytext[0];}


"+" {token('+'); return yytext[0];}
"-" {token('-'); return yytext[0];}
"*" {token('*'); return yytext[0];}
"/" {token('/'); return yytext[0];}
"mod" {token('MOD'); return MOD;}
":=" {token(':='); return AS;}
"<" {token('<'); return yytext[0];}
"<=" {token('<='); return LE;}
">=" {token('>='); return GE;}
">" {token('>'); return yytext[0];}
"=" {token('='); return yytext[0];}
"not=" {token('not='); return NE;}
"and" {token('and'); return AND;}
"or" {token('or'); return OR;}
"not" {token('not'); return NOT;}

"array" {token(ARRAY); return ARRAY;}
"begin" {token(BEGIN); return BEG;}
"bool" {token(BOOL); return BOOL;}
"char" {token(CHAR); return CHAR;}
"const" {token(CONST); return CONST;}
"decreasing" {token(DECREASING); return DECREASING;}
"default" {token(DEFAULT); return DEFAULT;}
"do" {token(DO); return DO;}
"else" {token(ELSE);return ELSE;}
"end" {token(END);return END;}
"exit" {token(EXIT);return EXIT;}
"false" {token(FALSE); yylval.b_v = 0;return val_BOOL;}
"for" {token(FOR); return FOR;}
"function" {token(FUNCTION); return FUNCTION;}
"get" {token(GET); return GET;}
"if" {token(IF); return IF;}
"int" {token(INT); return INT;}
"loop" {token(LOOP); return LOOP;}
"of" {token(OF); return OF;}
"put" {token(PUT);return PUT;}
"procedure" {token(PROCEDURE); return PROCEDURE;}
"real" {token(REAL); return REAL;}
"result" {token(RESULT); return RESULT;}
"return" {token(RETURN); return RETURN;}
"skip" {token(SKIP); return SKIP;}
"string" {token(STRING); return STRING;}
"then" {token(THEN); return THEN;}
"true" {token(TRUE); yylval.b_v= 1;return val_BOOL;}
"var" {token(VAR); return VAR;}
"when" {token(WHEN); return WHEN;}


{IDENTIFIER} {
        tokenString(identifer,yytext);
        //yylval = insert(table,yytext);
        //cout << "yytext: " << yytext << endl;
        yylval.s_v = new string(yytext);
        return ID;
}


{REAL} {
                tokenString(Real,yytext);
                yylval.r_v = atof(yytext);        
                return val_REAL;
}

{INTEGER} {
        tokenString(Integer,yytext); 
        yylval.i_v = atoi(yytext);
        return val_INTEGER;
}



"\"" {
        LIST;
        BEGIN STR;
}

<STR>"\"" {
        char c = yyinput();
        if(c == '"'){
                strcat(buf,"\"\"");
                strcat(strbuf,"\"");
        }else{
                //tokenString(String,strbuf);
                strcat(buf,"\"");
                printf("<String: %s>\n",strbuf);
                yylval.s_v = new string(strbuf);
                strbuf[0] = '\0';
                unput(c);
                BEGIN 0;
                
                return val_STR;
        }
}


<STR>[^\n] {
        LIST;
        strcat(strbuf,yytext);
}

"%".* {
        LIST;
}

"{%" {
        LIST;
        BEGIN COMMENT;
}


<COMMENT>"%}" {
        LIST;
        BEGIN 0;
}


<COMMENT>\n {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
}

<COMMENT>. {
        LIST;
}

{WHITESPACE} {
        LIST;
}

\n {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
}

.       {
        LIST;
        printf("%d:%s\n", linenum, buf);
        //exit(1);
        }

%%

