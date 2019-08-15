
#include "parser.h"
#include "scanner.h"

#include <stdio.h>

int parse_P()
{
	return parse_E() && expect_token(TOKEN_EOF);
}

int parse_E()
{
	return parse_T() && parse_E_prime();
}

int parse_E_prime()
{
	token_t t = scan_token();
	if(t == TOKEN_PLUS) {
		return parse_T() && parse_E_prime();
	} else {
		putback_token(t);
		return 1;
	}
}

int parse_T()
{
	return parse_F() && parse_T_prime();
}

int parse_T_prime()
{
	token_t t = scan_token();
	if(t == TOKEN_MULTIPLY) {
		return parse_F() && parse_T_prime();
	} else {
		putback_token(t);
		return 1;
	}
}

int parse_F()
{
	token_t t = scan_token();
	if(t == TOKEN_LPAREN) {
		return parse_E() && expect_token(TOKEN_RPAREN);
	} else if(t == TOKEN_INT) {
		return 1;
	} else {
		printf("parse error: unexpected token: %s", token_string(t));
		return 0;
	}
}
