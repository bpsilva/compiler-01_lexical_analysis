%{

#define TRUE 1
#define FALSE 0
#include<string.h>
#include "tokens.h"

int lineNumber;
int running = TRUE;
%}



%%

word 		{return KW_WORD;}
bool 		{return KW_BOOL;}
byte		{return KW_BYTE;}
if		{return KW_IF;}
then		{return KW_THEN;}
else		{return KW_ELSE;}
loop		{return KW_LOOP;}
input		{return KW_INPUT;}
return		{return KW_RETURN;}
output		{return KW_OUTPUT;}


[-,;:(){}+*/<>=!&$]		{return yytext[0];}
"["				{return yytext[0];}
"]"				{return yytext[0];}

"<="		{return OPERATOR_LE;}
">="		{return OPERATOR_GE;}
"=="		{return OPERATOR_EQ;}
"!="		{return OPERATOR_NE;}
"&&"		{return OPERATOR_AND;}
"||"		{return OPERATOR_OR;}


[0-9]+ 		{return LIT_INTEGER;}

FALSE		{return LIT_FALSE;}
TRUE		{return LIT_TRUE;}
[A-Za-z_][A-Za-z_0-9]*		{return TK_IDENTIFIER;}
"'"."'" 	{return LIT_CHAR;}
["].*["]	{return LIT_STRING;}
" "
[0-9]+[A-Za-z_]+[A-Za-z_0-9]*		{return TOKEN_ERROR;}
. {return TOKEN_ERROR;}

%%
int main()
{
int tok;	
	while(running)
	{
		tok = yylex();
		printf("%i\n", tok);
	}
	return 0;
}

int yywrap()
{
	return 1;
}
