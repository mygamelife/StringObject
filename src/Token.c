#include "Token.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "StringObject.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "IdentifierToken.h"
#include "ErrorCode.h"
#include "CException.h"

char *numSet = "0123456789";
char *opSet = "+-*/%^&|";
char *idenSet = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

Token *getToken(String *expression)
{	
	char *tempIden; //temporary store idendifier name
	stringTrim(expression);	//Remove all the spaces in string

	/*Character at first position*/
	int charAtThisPos = stringCharAt(expression ,  expression->startindex);

	if(charAtThisPos >= 48 && charAtThisPos <= 57) //first character is number
	{	
		
		String *removedWord = stringRemoveWordContaining (expression , numSet);	//Remove numbers in string
		char *numSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed numbers become substring
		charAtThisPos = expression->string[expression->startindex];
		
		//if character behind number token is alphabet A~Z or a~z it is invalid type
		if(charAtThisPos >= 65 && charAtThisPos <= 90 || charAtThisPos >= 97 && charAtThisPos <= 122 )
		{
			Throw(ERR_INVALID_FORMAT);
		}
		
		//if character behind number token is '_' it is identifier
		if(charAtThisPos == 95)
		{
			String *removedWord = stringRemoveWordContaining (expression , idenSet);
			char *idenSubString = stringSubStringInChars(removedWord , removedWord->length);
			tempIden = strcat(numSubString , idenSubString);
			Identifier *iden = identifierNew(tempIden);
		
			return (Token*)iden;
		}
		
		int integer = subStringToInteger(numSubString); //Convert substring to integer
		Number *num = numberNew(integer); //get integer from subStringToInteger and create a new Number Token
		
		return (Token*)num;
	}
	
	//A~Z (65~90) , (a~z) 97~122 , ('_') 95
	else if(charAtThisPos == 95 || charAtThisPos > 65 && charAtThisPos < 90 || charAtThisPos > 97 && charAtThisPos < 122 ) 
	{
		String *removedWord = stringRemoveWordContaining (expression , idenSet); //Remove identifier from string
		char *idenSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed identifier become substring
		Identifier *iden = identifierNew(idenSubString); //create a new identifier token
		
		return (Token*)iden;
	}
	
	//first character is operator
	String *removedWord = stringRemoveWordContaining (expression , opSet); //Remove operator in string	
	char *opSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed operator become substring
	Operator *op = operatorNewByName(opSubString);
		
	return (Token*)op;
}
