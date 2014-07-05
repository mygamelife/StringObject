#include "StringObject.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

Strings *StringNew(int length)
{
	Strings *str = malloc(sizeof(Strings));
	str->strings = malloc(sizeof(char) * length);
	str->startindex = 0;
	str->length = length;
}

/* To remove all spaces in StringChar[]
 * input :
 *		StringChar[] user input character
 * output:
 *		str->strings to store string after removed spaces
*/
void StringTrim(Strings *str , char StringChar[])
{
	int i = 0 , length = 0;
	
	length = strlen(StringChar);
 
	for(i ; i < length ; i++)
	{
		if(!isspace(StringChar[i])) 
		{
			str->strings[str->startindex] = StringChar[i];
			str->strings[str->startindex+1] = 0; //insert new null delimiter
			str->startindex++;
		}
	}
}

/* To remove words contain in ContainSet
 * input :
 *		ContainSet character need to be me remove
 * return:
 *		Return the deleted words in ContainSet
*/
Strings *StringRemoveWordContaining(Strings *str , char *ContainSet)
{
	int i = 0, j = 0 , k = 0;
	Strings *RemovedWord;
	
	while(i < strlen(str->strings))
	{
		while(j != strlen(ContainSet))
		{
			if(str->strings[i] == ContainSet[j])
				printf("%c\n" , str->strings[i]);

			j++;
		}
		
		i++;
		j = 0;
	}
	
	return RemovedWord;
}