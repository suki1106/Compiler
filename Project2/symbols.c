#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbols.h"

#define TABLE_SIZE 1000



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