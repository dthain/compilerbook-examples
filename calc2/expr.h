/*
expr.h defines the structure of an expression node,
and the operations that can be performed upon it.
Note some things about this file that you should emulate:
- Every symbol in expr.[ch] begins with expr_.
- Use enumerations to define variant types.
- Build complex trees one node at a time.
- Define methods with recurse over those trees.
*/

#ifndef EXPR_H
#define EXPR_H

typedef enum {
	EXPR_ADD,
	EXPR_SUBTRACT,
	EXPR_DIVIDE,
	EXPR_MULTIPLY,
	EXPR_VALUE
} expr_t;

struct expr {
       expr_t kind;
       double value;
       struct expr *left;
       struct expr *right;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
struct expr * expr_create_value( double value );

void          expr_print( struct expr *e );
void          expr_delete( struct expr *e );
double        expr_evaluate( struct expr *e );

#endif

