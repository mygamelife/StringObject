#include "StringObject.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

Strings *StringNew()
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
 *		ContainSet character need to be remove
 * return:
 *		Return the RemovedWord
*/
Strings *StringRemoveWordContaining(Strings *str , char *ContainSet)
{
	int i = 0, j = 0 , k = 0 , FirstFound = 0 , SecondFound = 0;
	
	Strings *RemovedWord = StringNew(); //create new Strings for RemovedWord
	str->length = strlen(str->strings); //assign original string length to str->length
	RemovedWord->strings = str->strings; 
	
	while(i < strlen(str->strings))
	{
		while(j != strlen(ContainSet))
		{
			if(str->strings[i] == ContainSet[j])
			{
				if(!FirstFound)
				{
					RemovedWord->startindex = i; //first character found	
					FirstFound = 1;
					if(i != 0)
						str->length = str->length - i;
					printf("First Character detected = %c\n\n" , str->strings[i]);
				}
				
				
				RemovedWord->length++; //one word is detected in ContainSet
				str->startindex = i+1;
				str->length--; //decrement once after one word removed
				printf("str->length = %d\n\n" , str->length);
			}
			
			j++;
		}
		
		i++;
		j = 0;
	}
jump:
	
	return RemovedWord;
}