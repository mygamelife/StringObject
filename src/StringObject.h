#ifndef StringObject_H
#define StringObject_H

typedef struct
{
	char *string;
	int startindex;
	int length;
}String;

String *stringNew(char *charString);
void stringTrimLeft(String *str);
void stringTrimRight(String *str);
void stringTrim(String *str);
String *stringRemoveWordContaining (String *str , char *containSet);
String *stringRemoveWordNotContaining (String *str , char *notContainSet);
int stringCharAt(String *str ,  int relativePos);
int stringRemoveChar(String *str);
void stringSkip(String *str , int numOfCharToSkip);
char *stringSubStringInChars(String *str , int length);
int subStringToInteger(char *subString);
void stringDel(String *str);
void subStringDel(char *subString);
#endif // StringObject_H
