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

       void test_StringRemoveWordContaining_MAXIS_should_remove_A(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew();

 StringTrim(str , "MAXIS");

 RemovedWord = StringRemoveWordContaining(str , "AI");





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((RemovedWord->startindex)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((RemovedWord->length)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringRemoveWordContaining_LECTURE_should_remove_CTU(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew();

 StringTrim(str , "LECTURE");

 RemovedWord = StringRemoveWordContaining(str , "UTC");





 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((RemovedWord->startindex)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((RemovedWord->length)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringRemoveWordContaining_321_plus_432_should_remove_321(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew();

 StringTrim(str , "321 + 432 ");

 RemovedWord = StringRemoveWordContaining(str , "01234");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((RemovedWord->startindex)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((RemovedWord->length)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}
