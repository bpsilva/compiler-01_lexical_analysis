#include "hash.h"


void init()
{
	int i;
		for(i = 0 ; i < TAM ; i++)
		{
			table[i] = 0;
		}
	}

void print()
{
hash_node* pointer;
int i = 0;
	for(i = 0 ; i < TAM ; i++)
	{
		for(pointer = table[i]; pointer !=0 ; pointer = pointer->prox)
		{
			printf("%s ", pointer->word);
		}
		printf("        ");
	}



}

void insert(char* text, int type){
	int address = genAddress(text);
	hash_node *pointer = table[address], *aux = table[address];
	int achou = 0;

	
	while(pointer!=0)
	{
		if(!strcmp(text, pointer->word))
		{
			
			achou = 1;
			
		}
	aux = pointer;
	pointer=pointer->prox;
	}
	
	if(achou == 0)
	{
		hash_node *node = (hash_node*)malloc(sizeof(hash_node));
		node->word = text;
		node->prox = 0;
		node->type = type;
		
		if(aux!=0)
		{
			aux->prox = node;			
		}
		else{
			table[address] = node;
			}
			
	}
	

}

int genAddress(char* word)
{
int i = 0;
int position = 0;
	for(i = 0; i< strlen(word);i++)
	{
	position += word[i];
	}
	position = position % TAM;

return position;
}
