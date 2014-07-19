#include "unity.h"
#include "StringObject.h"


void setUp(void)

{

}



void tearDown(void)

{

}









void test_stringNewX_given_NEW_startindex_0_and_length_0(void)

{

 String *str = stringNew("NEW");



 UnityAssertEqualString((const char*)("NEW"), (const char*)(str->string), (((void *)0)), (_U_UINT)20);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_0(void)

{

 String *str = stringNew(" 2+2");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_1(void)

{

 String *str = stringNew("\t\tABC");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_2(void)

{

 String *str = stringNew("\t  C \tHAOS");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimRight_should_skip_spaces_on_left_sides_0(void)

{

 String *str = stringNew("SLEEPLY ");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimRight_should_skip_spaces_on_left_sides_1(void)

{

 String *str = stringNew("  DRY ");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrimRight_should_skip_spaces_on_left_sides_2(void)

{

 String *str = stringNew("\t\tLO VE\t\t");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_0(void)

{

 String *str = stringNew(" Stress ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_1(void)

{

 String *str = stringNew("  2 +6 ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_2(void)

{

 String *str = stringNew("\t \t 13 +20 \t \t ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

}









void test_stringRemoveWordContaining_given_HELLO_should_remove_L(void)

{

 String *str = stringNew(" HELLO");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "L");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

}









void test_stringRemoveWordContaining_MAXIS_should_remove_A(void)

{

 String *str = stringNew("MAXIS");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "AI");





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordContaining_Beef_should_remove_f(void)

{

 String *str = stringNew(" Beef ");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "f");





 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordContaining_space_tab_21_plus_32_space_tab_should_remove_21(void)

{

 String *str = stringNew(" \t 21 + 32  \t ");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "01234");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

}













void test_stringRemoveWordContaining_tab_space_negative_10_plus_2_space_should_remove_10(void)

{

 String *str = stringNew("\t -10 + 2 ");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "43210");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordContaining_tab_AB_plus_CD_tab_should_remove_nothing(void)

{

 String *str = stringNew("\tAB + CD\t");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "XYZ");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC(void)

{

 String *str = stringNew(",ABC");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "A");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordNotContaining_Jel_apostrophe_ly_should_remove_Jel(void)

{

 String *str = stringNew("Jel'ly");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "'");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)277, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)281, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordNotContaining_Lady_square_bracket_should_remove_square_bracket(void)

{

 String *str = stringNew("Lady[]");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "[]");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

}











void test_stringRemoveWordNotContaining_Oil_comma_should_remove_Oil_comma(void)

{

 String *str = stringNew("Oil,");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , ";'[");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)316, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT);

}
