#include "unity.h"
#include "StringObject.h"


void setUp(void)

{

}



void tearDown(void)

{

}



       void test_StringTrim_should_skip_spaces_in_left_sides_and_store_in_strStrings(void)

{

 Strings *str = StringNew();

 StringTrim(str , " 2+2");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringTrim_should_skip_spaces_in_right_sides_and_store_in_strStrings(void)

{

 Strings *str = StringNew();

 StringTrim(str , "4+8+1  ");



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringTrim_should_skip_all_spaces_and_store_in_strStrings(void)

{

 Strings *str = StringNew();

 StringTrim(str , " 4 - 2 +   3  ");



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringRemoveWordContaining_given_HELLO_should_remove_Lx2(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew();

 StringTrim(str , "HELLO");

 RemovedWord = StringRemoveWordContaining(str , "L");





 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((RemovedWord->startindex)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((RemovedWord->length)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringRemoveWordContaining_MAXIS_should_remove_A_and_I(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew();

 StringTrim(str , "MAXIS");

 RemovedWord = StringRemoveWordContaining(str , "AI");



 printf("RemovedWord->strings = %c\n" , RemovedWord->strings[RemovedWord->startindex]);

 printf("str->strings = %c\n" , str->strings[str->startindex]);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((RemovedWord->startindex)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((RemovedWord->length)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

}
