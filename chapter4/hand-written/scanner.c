#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

static int putback_valid = 0;
static token_t putback_value = TOKEN_ERROR;

token_t scan_token()
{
	if(putback_valid) {
		putback_valid = 0;
		return putback_value;
	}

	int c;
retry:
	c = fgetc(stdin);

	if(c=='*') {
		return TOKEN_MULTIPLY;
	} else if(c=='+') {
		return TOKEN_PLUS;
	} else if(c=='(') {
		return TOKEN_LPAREN;
	} else if(c==')') {
		return TOKEN_RPAREN;
	} else if(isdigit(c)) {
		do {
			c = fgetc(stdin);
		} while(isdigit(c));
		ungetc(c,stdin);
		return TOKEN_INT;
	} else if(isspace(c)) {
		goto retry;
	} else if(c==EOF) {
		return TOKEN_EOF;
	} else {
		return TOKEN_ERROR;
	}
}

int expect_token( token_t kind )
{
	token_t t = scan_token();
	if(t==kind) {
		return 1;
	} else {
		putback_token(t);
		return 0;
	}
}

void putback_token( token_t t )
{
	putback_value = t;
	putback_valid = 1;
}

const char * token_string( token_t t )
{
	switch(t) {
		case TOKEN_MULTIPLY:
			return "*";
		case TOKEN_PLUS:
			return "+";
		case TOKEN_LPAREN:
			return "(";
		case TOKEN_RPAREN:
			return ")";
		case TOKEN_INT:
			return "INTEGER";
		case TOKEN_EOF:
			return "EOF";
		case TOKEN_ERROR:
		default:
			return "ERROR";
	}
}

