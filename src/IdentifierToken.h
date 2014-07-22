#ifndef IdentifierToken_H
#define IdentifierToken_H
#include "Token.h"

typedef struct
{
	TokenType type;
	char *name;
}Identifier;

Identifier *identifierNew(char *name);
void identifierDel(Identifier *iden);
#endif // IdentifierToken_H
