#ifndef symbols_h
#define symbols_h



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


unsigned long hash(const char *str);
entry *new_node(const char *key, int value);
symbol_table *create();
int insert(symbol_table *table, const char *key);
int lookup(symbol_table *table, const char *key);
void dump(symbol_table * table);
void free_table(symbol_table *table);



#endif