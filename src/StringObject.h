#ifndef StringObject_H
#define StringObject_H

typedef struct
{
	char *strings;
	int startindex;
	int length;
}Strings;

Strings *stringNew();
void StringTrim(Strings *str, char StringChar[]);
Strings *stringRemoveWordContaining (Strings *str , char *ContainSet);
Strings *stringRemoveWordNotContaining (Strings *str , char *notContainSet);
#endif // StringObject_H
