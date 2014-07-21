#ifndef NumberToken_H
#define NumberToken_H
#include "Token.h"

typedef struct
{
	TokenType type;
	int value;
}Number;

Number *numberNew(int value);
#endif // NumberToken_H
