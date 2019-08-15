#ifndef SCANNER_H
#define SCANNER_H

typedef enum {
  TOKEN_PLUS,
  TOKEN_MULTIPLY,
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_INT,
  TOKEN_ERROR,
  TOKEN_EOF
} token_t;

token_t scan_token();
int     expect_token( token_t t );
void    putback_token( token_t t );
const char * token_string( token_t t );

#endif
