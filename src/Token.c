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

/* To extract out number token , identifier token or operator token from the expression string
 * input :
 *			expression is the string that we wanted to extract the token
 * output :
 *			return number token if number is found in string
 *			return idendifier token if identifier is found in string
 * 			return operator token if operator is found in string
 */
Token *getToken(String *expression)
{	
	char *tempIden; //temporary store idendifier name
	stringTrim(expression);	//Remove all the spaces in string

	/*Character at first position*/
	int charAtThisPos = expression->startindex;
	
	//if character start with numbers it is number token
	if(stringCharAtInSet(expression , charAtThisPos , numSet))
	{	
		
		String *removedWord = stringRemoveWordContaining (expression , numSet);	//Remove numbers in string
		char *numSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed numbers become substring
		charAtThisPos = expression->startindex;
		
		//if character behind number token is alphabet A~Z/a~z or '_' it is not number type		
		if(stringCharAtInSet(expression , charAtThisPos , alphaSet))
			Throw(ERR_NOT_NUMBER_TOKEN);
		
		int integer = subStringToInteger(numSubString); //Convert substring to integer
		Number *num = numberNew(integer); //get integer from subStringToInteger and create a new Number Token
		
		return (Token*)num;
	}
	
	//if character start with A~Z/a~z or '_' it is identifier token
	else if(stringCharAtInSet(expression , charAtThisPos , alphaNumericSet)) 
	{
		String *removedWord = stringRemoveWordContaining (expression , alphaNumericSet); //Remove identifier from string
		char *idenSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed identifier become substring
		Identifier *iden = identifierNew(idenSubString); //create a new identifier token
		
		return (Token*)iden;
	}
	
	//if character not start with A~Z/a~z , '_' or numbers it is operator token
	String *removedWord = stringRemoveWordContaining (expression , opSet); //Remove operator in string	
	char *opSubString = stringSubStringInChars(removedWord , removedWord->length); //Removed operator become substring
	Operator *op = operatorNewByName(opSubString);
		
	return (Token*)op;
}
