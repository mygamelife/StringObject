#include "Token.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "StringObject.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "IdentifierToken.h"

char *numSet = "0123456789";
char *opSet = "+-*/%^&|";

Token *getToken(String *expression)
{	
	stringTrim(expression);	//Remove all the spaces in string
	
	/*Character at this position*/
	int charAtThisPos = stringCharAt(expression ,  expression->startindex);

	printf("charAtThisPos = %c\n\n" , charAtThisPos);
	if(charAtThisPos > 48 && charAtThisPos < 57) //first character is 0~9
	{	
		String *removedWord = stringRemoveWordContaining (expression , numSet); //Remove numbers in string	
		char *numSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed numbers become substring
		int integer = subStringToInteger(numSubString); //Convert substring to integer
		Number *num = numberNew(integer); //get integer from subStringToInteger and create a new Number Token
		
		return (Token*)num;
	}
	
	String *removedWord = stringRemoveWordContaining (expression , opSet); //Remove operator in string	
	char *opSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed operator become substring
	Operator *op = operatorNewByName(opSubString);
		
	return (Token*)op;

}
