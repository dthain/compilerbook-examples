#include "parser.h"
#include <stdio.h>

int main()
{
	printf("Enter an expression, followed by Control-D to indicate EOF.\n");
	if(parse_P()) {
		printf("Expression is valid.\n");
		return 0;
	} else {
		printf("Expression is NOT valid.\n");
		return 1;
	}
}

