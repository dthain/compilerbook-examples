/*
Main program of calculator example.
*/

#include <stdio.h>

/* Clunky: Declare the parse function generated from parser.bison */
extern int yyparse();

/* Clunky: Declare the result of the parser from parser.bison */
extern double parser_result;

int main( int argc, char *argv[] )
{
	printf("CSE 40243 Expression Interpreter\n");
	printf("Enter an infix expression using the operators +-*/() ending with ;\n\n");

	if(yyparse()==0) {
		printf("result: %lg\n",parser_result);
		return 0;
	} else {
		printf("parse failed!\n");
		return 1;
	}
}

