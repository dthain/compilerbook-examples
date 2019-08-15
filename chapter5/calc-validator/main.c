/*
Main program of calculator example.
Validate whether the input matches the grammar.
*/

#include <stdio.h>

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();

int main()
{
	if(yyparse()==0) {
		printf("Parse successful!\n");
		return 0;
	} else {
		printf("Parse failed.\n");
		return 1;
	}
}

