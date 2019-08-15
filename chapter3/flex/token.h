#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
     TOKEN_EOF=0,
     TOKEN_WHILE,
     TOKEN_ADD,
     TOKEN_IDENT,
     TOKEN_NUMBER,
     TOKEN_ERROR
} token_t;

#endif
