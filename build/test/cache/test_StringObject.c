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

 Strings *str = StringNew(50);

 StringTrim(str , " 2+2");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringTrim_should_skip_spaces_in_right_sides_and_store_in_strStrings(void)

{

 Strings *str = StringNew(50);

 StringTrim(str , "4+8+1  ");



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringTrim_should_skip_all_spaces_and_store_in_strStrings(void)

{

 Strings *str = StringNew(50);

 StringTrim(str , " 4 - 2 +   3  ");



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((strlen(str->strings))), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

}



       void test_StringRemoveWordContaining_given_3_plus_3_should_remove_two_3(void)

{

 Strings *RemovedWord;

 Strings *str = StringNew(50);

 StringTrim(str , " 3 + 4");

 StringRemoveWordContaining(str , "1234");

}
