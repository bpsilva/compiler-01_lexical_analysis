#include "hash.h"
#define FAIL "---FAILED---"
#define PASS "***PASSED***"

char* initTest()
{
int i = 0;

	init();
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

	init();
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
init();
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
	init();
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
	printf("initTeste: %s\n", initTest());
	printf("genPositionTest: %s\n", genAddressTest());
	printf("insertTestSimple: %s\n", insertTestSimple());
	printf("insertTestEqualWords: %s\n", insertTestEqualWords());
	printf("insertTwoWordsTest: %s\n", insertTwoWordsTest());
}
