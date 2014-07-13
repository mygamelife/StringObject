#include "StringObject.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

Strings *stringNew()
{
	Strings *str = malloc(sizeof(Strings));
	str->strings = malloc(sizeof(char));
	str->startindex = 0;
	str->length = 0;
}

/* To remove all spaces in StringChar[]
 * input :
		index to remember the position of str->strings
 *		StringChar[] user input character
 * output:
 *		str->strings to store string after removed spaces
*/
void StringTrim(Strings *str , char StringChar[])
{
	int i = 0 , length = 0 , index = 0;
	
	length = strlen(StringChar);
 
	for(i ; i < length ; i++)
	{
		if(!isspace(StringChar[i])) 
		{
			str->strings[index] = StringChar[i];
			str->strings[index+1] = 0; //insert new null delimiter
			index++;
		}
	}
}

/* To remove words contain in ContainSet
 * input :
 *		ContainSet character that need to be remove
 * return:
 *		Return the removedWord start index and length
*/
Strings *stringRemoveWordContaining(Strings *str , char *ContainSet)
{
	int i = 0, j = 0 , k = 0 , firstFound = 0 , notInSet = 0;
	
	Strings *removedWord = stringNew(); //create new Strings for removedWord
	str->length = strlen(str->strings); //assign original string length to str->length
	removedWord->strings = str->strings; 
	
	while(i < strlen(str->strings))
	{
		while(j != strlen(ContainSet))
		{
			if(str->strings[i] == ContainSet[j])
			{
				if(!firstFound)
				{
					removedWord->startindex = i; //first character found	
					firstFound = 1;
					if(i != 0)
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
 *		notContainSet character that don't need to be remove
 * return:
 *		Return the removedWord start index and length
*/
Strings *stringRemoveWordNotContaining(Strings *str , char *notContainSet)
{
	int i = 0, j = 0 , k = 0 , firstFound = 0 , notInSet = 0;
	
	Strings *notremovedWord = stringNew(); //create new Strings for removedWord
	str->length = strlen(str->strings); //assign original string length to str->length
	notremovedWord->strings = str->strings; 
	printf("%s\n",str->strings);
	
	while(i < strlen(str->strings))
	{
		while(j != strlen(notContainSet))
		{
			if(notremovedWord->strings[i] != notContainSet[j])
			{
				if(!firstFound)
				{
					notremovedWord->startindex = i; //first character found	
					firstFound = 1;
					if(i != 0)
						str->length = str->length - i;
					printf("First Character not in ContainSet = %c\n\n" , str->strings[i]);
				}
				
				notremovedWord->length++; //one word is detected in ContainSet
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
		{
			printf("Character in notcontainset = %c\n\n" , str->strings[str->startindex]);
			goto end;
		}
jump:		
		i++;		
		j = 0;
	}	

end:
	return notremovedWord;
}