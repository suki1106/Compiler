%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n", #t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}

#define MAX_LINE_LENG 256
#define TABLE_SIZE 1000

int linenum = 1;
char buf[MAX_LINE_LENG];
char strbuf[MAX_LINE_LENG];



typedef struct node{
    char *key; // id
    int value; 
    struct node* next;
} entry;

typedef struct {
    entry **nodes;
    char ** identifiers;
    int index;
} symbol_table;

// djb2 hash
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c = 0;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  //  hash * 33 +c
    }
    return hash;
}


entry *new_node(const char *key, int value) {
    entry *node = malloc(sizeof(entry));
    node->key = strdup(key);
    //strcpy(node->key,key);
    node->value = value;
    return node;
}


symbol_table *create() {
    symbol_table *table = malloc(sizeof(symbol_table));
    table->identifiers = calloc(TABLE_SIZE,sizeof(char*));
    table->nodes = calloc(TABLE_SIZE, sizeof(entry *));
    table->index = 0;
    
    return table;
}

int insert(symbol_table *table, const char *key) {
    //strcpy(table->identifiers[value],key); 


    unsigned long index = hash(key) % TABLE_SIZE;
    entry *node = table->nodes[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            // already exists
            return -1;
        }
        node = node->next;
    }
    // doesn't exist

    int value = table->index++;
    table->identifiers[value] = strdup(key);
    node = new_node(key, value);
    node->next = table->nodes[index];
    table->nodes[index] = node;
    return value;
}


int lookup(symbol_table *table, const char *key) {
    unsigned long index = hash(key) % TABLE_SIZE;
    entry *node = table->nodes[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    // Key not found
    return -1;
}

void dump(symbol_table * table){
    for(int i = 0 ; i<table->index;i++){
        printf("%d : %s\n" , i , table->identifiers[i]);
    }
}


void free_table(symbol_table *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        entry *node = table->nodes[i];
        while (node) {
            entry *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    for(int i = 0 ; i < table->index ; i++){
        free(table->identifiers[i]);
    }
    free(table->identifiers);
    free(table->nodes);
    free(table);
}
symbol_table* table;
%}

LETTER [A-za-z]
DIGIT [0-9]
DIGITS {DIGIT}+
INTEGER {DIGITS}
REAL {DIGITS}("."{DIGITS})
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
WHITESPACE [ \t]+



%x COMMENT
%x STR


%%

"." {token('.');}
"," {token(',');}
":" {token(":");}
";" {token(";");}
"(" {token('(');}
")" {token(')');}
"[" {token('[');}
"]" {token(']');}
"{" {token('{');}
"}" {token('}');}



"+" {token('+');}
"-" {token('-');}
"*" {token('*');}
"/" {token('/');}
"mod" {token('MOD');}
":=" {token(':=');}
"<" {token('<');}
"<=" {token('<=');}
">=" {token('>=');}
">" {token('>');}
"=" {token('=');}
"not=" {token('not=');}
"and" {token('and');}
"or" {token('or');}
"not" {token('not');}

"array" {token(ARRAY);}
"begin" {token(BEGIN);}
"bool" {token(BOOL);}
"char" {token(CHAR);}
"const" {token(CONST);}
"decreasing" {token(DECREASING);}
"default" {token(DEFAULT);}
"do" {token(DO);}
"else" {token(ELSE);}
"end" {token(END);}
"exit" {token(EXIT);}
"false" {token(FALSE);}
"for" {token(FOR);}
"function" {token(FUNCTION);}
"get" {token(GET);}
"if" {token(IF);}
"int" {token(INT);}
"loop" {token(LOOP);}
"of" {token(OF);}
"put" {token(PUT);}
"procedure" {token(PROCEDURE);}
"real" {token(REAL);}
"result" {token(RESULT);}
"return" {token(RETURN);}
"skip" {token(SKIP);}
"string" {token(STRING);}
"then" {token(THEN);}
"true" {token(TRUE);}
"var" {token(VAR);}
"when" {token(WHEN);}


{IDENTIFIER} {
        tokenString(identifer,yytext);
        insert(table,yytext);
}


{REAL} {tokenString(Real,yytext);}

{INTEGER} {tokenString(Integer,yytext);}



"\"" {
        LIST;
        BEGIN STR;
}

<STR>"\"" {
        char c = input();
        if(c == '"'){
                strcat(buf,"\"\"");
                strcat(strbuf,"\"");
        }else{
                tokenString(String,strbuf);
                strbuf[0] = '\0';
                unput(c);
                BEGIN 0;
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

%%

int main(int argc,char * argv[]){
        table = create();
        extern FILE* yyin;
        if(argc == 2){
            yyin = fopen(argv[1],"r");
        }
        yylex();
        printf("\nSymbol Table:\n");
        dump(table);
        free_table(table);
        fflush(yyout);
        exit(0);
}
