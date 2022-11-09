#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main()
{
	yyin = fopen("program.bminor","r");
	if(!yyin) {
		printf("could not open program.c!\n");
		return 1;
	}

	while(1) {
		token_t t = yylex();
		if(t==TOKEN_EOF) break;
		printf("token: %d  text: %s\n",t,yytext);
	}
}
