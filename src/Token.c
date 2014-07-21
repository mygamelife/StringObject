#include "Token.h"
#include "StringObject.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "NumberToken.h"
#include "OperatorToken.h"

/* Identifier 
 */
Identifier *identifierNew(char *name)
{
	Identifier *iden = malloc(sizeof(Identifier)); //*iden = identifier pointer
	iden->type = IDENTIFIER_TOKEN;
	iden->name = name;
	
	return iden;
}