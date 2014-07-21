#ifndef Token_H
#define Token_H
#include "StringObject.h"

typedef enum
{
	UNKOWN,
	NUMBER_TOKEN,
	OPERATOR_TOKEN,
	IDENTIFIER_TOKEN
}TokenType;

typedef struct
{
	TokenType type;
	char *name;
}Identifier;

typedef struct
{
	TokenType type;
}Token;

Identifier *identifierNew(char *name);
Token *getToken(String *expression);

#endif // Token_H
