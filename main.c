// Bruno Pinto Silva Cartão: 217446 bpsilva

#include "hash.h"
#include "tokens.h"
int main()
{
int token;
initMe();
int i = 0;
	while(isRunning())
	{	
	token =  yylex();
        switch(token)
		{
		case KW_WORD: 
			printf(" KW_WORD ");break;
		case KW_BOOL: 
			printf(" KW_BOOL ");break;
		case KW_BYTE: 
			printf(" KW_BYTE ");break;
		case KW_LOOP: 
			printf(" KW_LOOP ");break;
		case KW_INPUT: 
			printf(" KW_INPUT ");break;
		case KW_IF: 
			printf(" KW_IF ");break;
		case KW_THEN:
			printf(" KW_THEN ");break;
		case KW_ELSE:
			printf(" KW_ELSE ");break;
		case KW_RETURN: 
			printf(" KW_RETURN ");break;
		case KW_OUTPUT: 
			printf(" KW_OUTPUT ");break;
		case TK_IDENTIFIER: 
			printf(" TK_IDENTIFIER ");break;
		case LIT_INTEGER: 
			printf(" LIT_INTEGER ");break;
		case OPERATOR_LE: 
			printf(" OPERATOR_LE ");break;
		case OPERATOR_GE: 
			printf(" OPERATOR_GE ");break;
		case OPERATOR_EQ: 
			printf(" OPERATOR_EQ ");break;
		case OPERATOR_NE: 
			printf(" OPERATOR_NE ");break;
		case OPERATOR_AND: 
			printf(" OPERATOR_AND ");break;
		case OPERATOR_OR: 
			printf(" OPERATOR_OR ");break; 
		case LIT_TRUE: 
			printf(" LIT_TRUE ");break;
		case LIT_FALSE: 
			printf(" LIT_FALSE ");break;
		case LIT_CHAR: 
			printf(" LIT_CHAR ");break;
		case LIT_STRING: 
			printf(" LIT_STRING ");break;
		case TOKEN_ERROR: 
			printf(" TOKEN_ERROR ");break;
		default: 
			printf("%c", token);
		}		
	
	}
	//print();
	return 0;
}
