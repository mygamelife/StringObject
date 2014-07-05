#ifndef StringObject_H
#define StringObject_H

typedef struct
{
	char *strings;
	int startindex;
	int length;
}Strings;

Strings *StringNew(int length);
void StringTrim(Strings *str, char StringChar[]);
Strings *StringRemoveWordContaining (Strings *str , char *ContainSet);
#endif // StringObject_H
