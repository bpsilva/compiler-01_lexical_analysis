#define TAM 20
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct hash
{
struct hash_node *prox;
char* word;
int type;
}hash_node;

hash_node *table[TAM];

void print();
void insert(char* text, int type);
void init();
int genAddress();


