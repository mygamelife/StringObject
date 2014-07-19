#include "StringObject.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Create a new String
 * input :
 *		charString is the string that we receive
 * return:
 *		str pointer
 */
String *stringNew(char *charString)
{
	String *str = malloc(sizeof(String));
	str->string = charString;
	str->startindex = 0;
	str->length = strlen(charString);
	
	return str;
}

/* To remove all spaces at left side
 * input :
 *		string
 * output:
 *		string after remove left side spaces
 */
void stringTrimLeft(String *str)
{
	int i = 0;

	while(isspace(str->string[i]))
	{
		i++;
		str->startindex = i;
	}
}

/* To remove all spaces at right side
 * input :
 *		string
 * output:
 *		string after remove right side spaces
 */
void stringTrimRight(String *str)
{
	int i = str->length;

	if(str->string[i] == 0)
		i--;
		
	while(isspace(str->string[i]))
	{		
		i--;
		str->length--;	
	}
}

/* To remove all spaces at left and right side in string
 * input :
 *		string
 * output:
 *		string after remove all spaces at left and right side
 */
void stringTrim(String *str)
{
	stringTrimLeft(str);
	stringTrimRight(str);
}

/* To remove words contain in ContainSet
 * input :
 *		ContainSet character that need to be remove
 * return:
 *		Return the removedWord start index and length
*/
String *stringRemoveWordContaining(String *str , char *containSet)
{
	int i = str->startindex , j = 0 , firstFound = 0 , notInSet = 0;
	
	String *removedWord = stringNew(str->string); //create new String for removedWord
	removedWord->length = 0;
	
	while(i < strlen(str->string))
	{
		while(j != strlen(containSet))
		{
			if(str->string[i] == containSet[j]) //searching is containSet inside the string
			{
				if(!firstFound)
				{
					removedWord->startindex = i; //first character found	
					firstFound = 1; //make sure this statement wont run again when the first character is found
		
					if(i != 0) // if first character found but not in first position
						str->length = str->length - i;
				}
				
				removedWord->length++; //one word is detected in ContainSet
				str->startindex = i+1;
				str->length--; //decrement once after one word removed
				notInSet = 0;
				
				goto jump;
			}
			
			if(firstFound == 1)
				notInSet = 1;
				
			j++;
		}
		
		if(notInSet == 1)
			goto end;

jump:		
		i++;		
		j = 0;
	}	

end:
	return removedWord;
}

/* To remove words not contain in ContainSet
 * input :
 *		notContainSet is character that don't need to be remove
 * return:
 *		Return the notRemovedWord start index and length
*/
String *stringRemoveWordNotContaining(String *str , char *notContainSet)
{
	int i = str->startindex , j = 0 , firstFound = 0 , notInSet = 0;
	
	String *notRemovedWord = stringNew(str->string); //create new String for notRemovedWord
	notRemovedWord->length = 0; 
	
	printf("notRemovedWord start index = %d\n\n" , notRemovedWord->startindex);
	printf("notRemovedWord length = %d\n\n" , notRemovedWord->length);
	printf("string start = %d\n\n" , str->startindex);
	printf("string length = %d\n\n" , str->length);
	
	while(i < strlen(str->string))
	{
		while(j != strlen(notContainSet))
		{
			if(str->string[i] != notContainSet[j])
			{
				if(!firstFound)
				{
					notRemovedWord->startindex = i; //first character found	
					firstFound = 1;
					if(i != 0)
						str->length = str->length - i;
				}
				
				notRemovedWord->length++; //one word is detected in ContainSet
				str->startindex = i+1;
				str->length--; //decrement once after one word removed
				notInSet = 0;
				
				printf("After remove\n");
				printf("notRemovedWord start index = %d\n\n" , notRemovedWord->startindex);
				printf("notRemovedWord length = %d\n\n" , notRemovedWord->length);	
				printf("string start = %d\n\n" , str->startindex);
				printf("string length = %d\n\n" , str->length);
				
				goto jump;
			}
			
			if(firstFound == 1)
				notInSet = 1;
				
			j++;
		}
		
		if(notInSet == 1)
			goto end;
jump:		
		i++;		
		j = 0;
	}	

end:
	return notRemovedWord;
}