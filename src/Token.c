#include "Token.h"
#include "StringObject.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "NumberToken.h"
#include "OperatorToken.h"
#include "IdentifierToken.h"

Token *getToken(String *expression)
{
	printf("expression = %s\n\n" , expression->string);
	printf("expression start = %d\n\n" , expression->startindex);
	printf("expression length = %d\n\n", expression->length);
	stringTrim(expression);
	
}
