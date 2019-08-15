
#include "expr.h"

#include <stdio.h>
#include <stdlib.h>

/*
Create one node in an expression tree and return the structure.
*/

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right )
{
	/* Shortcut: sizeof(*e) means "the size of what e points to" */
	struct expr *e = malloc(sizeof(*e));

	e->kind = kind;
	e->value = 0;
	e->left = left;
	e->right = right;

	return e;
}

struct expr * expr_create_value( double value )
{
	struct expr *e = expr_create(EXPR_VALUE,0,0);
	e->value = value;
	return e;
}

/*
Recursively delete an expression tree.
*/

void expr_delete( struct expr *e )
{
	/* Careful: Stop on null pointer. */
	if(!e) return;
	expr_delete(e->left);
	expr_delete(e->right);
	free(e);
}

/*
Recursively print an expression tree by performing an
in-order traversal of the tree, printing the current node
between the left and right nodes.
*/

void expr_print( struct expr *e )
{
	/* Careful: Stop on null pointer. */
	if(!e) return;

	printf("(");

	expr_print(e->left);

	switch(e->kind) {
		case EXPR_ADD:
			printf("+");
			break;
		case EXPR_SUBTRACT:
			printf("-");
			break;
		case EXPR_MULTIPLY:
			printf("*");
			break;
		case EXPR_DIVIDE:
			printf("/");
			break;
		case EXPR_VALUE:
			printf("%lg",e->value);
			break;
	}

	expr_print(e->right);
	printf(")");
}

/*
Recursively evaluate an expression by performing
the desired operation and returning it up the tree.
*/

double expr_evaluate( struct expr *e )
{
	/* Careful: Return zero on null pointer. */
	if(!e) return 0;

	double l = expr_evaluate(e->left);
	double r = expr_evaluate(e->right);

	switch(e->kind) {
		case EXPR_ADD:
			return l+r;
		case EXPR_SUBTRACT:
			return l-r;
		case EXPR_MULTIPLY:
			return l*r;
		case EXPR_DIVIDE:
			if(r==0) {
				printf("runtime error: divide by zero\n");
				exit(1);
			}
			return l/r;	
		case EXPR_VALUE:
			return e->value;
	}

	return 0;
}
