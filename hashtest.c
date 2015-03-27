// Bruno Pinto Silva Cartão: 217446 bpsilva

#include "hash.h"
#define FAIL "---FAILED---"
#define PASS "***PASSED***"

char* initMeTest()
{
int i = 0;

	initMe();
	for(i = 0 ; i < TAM ; i++)
	{
		if(table[i]!= 0)
		{
			return FAIL;
		}
	}

	return PASS;
}

char* insertTestSimple()
{

	char* palavraTeste = "palavrateste";
	int hashPosition = genAddress(palavraTeste);
	hash_node* pointer;

	initMe();
	insert(palavraTeste, 0);

	for(pointer = table[hashPosition] ;pointer != 0 ; pointer = pointer->prox)
	{
		if(strcmp(palavraTeste, pointer->word) == 0)
			return PASS;
	}
	
	return FAIL;
}

char* insertTestEqualWords()
{

char* palavraTeste = "palavrateste2";
int hashPosition = genAddress(palavraTeste);

int counter = 0, i = 0;
initMe();
hash_node* pointer = table[0];
insert(palavraTeste, 0);
insert(palavraTeste, 0);

	for(i = 0 ; i < TAM ; i++)
	{
		for(pointer = table[i]; pointer !=0 ; pointer = pointer->prox)
		{
			if(strcmp(palavraTeste, pointer->word) == 0)
				counter++;
		}
	}

	if(counter == 1)
	{
		return PASS;
	}else{
			return FAIL;
		}
}

char* insertTwoWordsTest()
{

	char* palavraTeste1 = "abcde";
	char *palavraTeste2 = "edacb";
	int hashPosition1 = genAddress(palavraTeste1);
	int hashPosition2 = genAddress(palavraTeste2);
	
	int  i = 0;
	initMe();
	insert(palavraTeste1, 0);
	insert(palavraTeste2, 0);
	hash_node* pointer1 = table[hashPosition1];
	hash_node* pointer2 = table[hashPosition1];

	while(pointer2->prox!=0)
		pointer2 = pointer2->prox;

	if(pointer1!=pointer2 && strcmp(palavraTeste1, pointer1->word)== 0 && strcmp(palavraTeste2, pointer2->word)== 0)
		return PASS;

	return FAIL;
}
char* genAddressTest()
{
	char* word = "AAAAAAAAAAAAAAAAAAAA";
	int expectedPosition = (20 * 65)%TAM;
	
	if(genAddress(word) == expectedPosition)
	{
		return PASS;
	}else{
		return FAIL;
		}
}





int main()
{
	printf("initMe Test: \t\t\t\t\t\t%s\n", initMeTest());
	printf("Address Generation Test: \t\t\t\t%s\n", genAddressTest());
	printf("Insertion Test (Simpĺe): \t\t\t\t%s\n", insertTestSimple());
	printf("Insertion Test (Two equal words): \t\t\t%s\n", insertTestEqualWords());
	printf("Insertion Test (Two diferent words, same address): \t%s\n", insertTwoWordsTest());
}
