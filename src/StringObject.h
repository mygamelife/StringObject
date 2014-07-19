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
int StringCharAt(String *str ,  int relativePos);
int StringRemoveChar(String *str);
#endif // StringObject_H
