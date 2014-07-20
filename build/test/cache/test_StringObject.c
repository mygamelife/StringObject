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











void test_stringCharAt_given_Apple_and_relative_position_1_should_return_p(void)

{

 int charAtThisPosition;

 String *str = stringNew("Apple");

 charAtThisPosition = stringCharAt(str , 1);





 UnityAssertEqualNumber((_U_SINT)((112)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT);

}











void test_stringCharAt_given_Orange_and_relative_position_6_should_return_negative_1(void)

{

 int charAtThisPosition;

 String *str = stringNew("Orange");

 charAtThisPosition = stringCharAt(str , 6);





 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)347, UNITY_DISPLAY_STYLE_INT);

}











void test_stringCharAt_given_2_plus_3_and_relative_position_negative_five_should_return_negative_1(void)

{

 int charAtThisPosition;

 String *str = stringNew("2+3");

 charAtThisPosition = stringCharAt(str , -5);





 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

}









void test_stringCharAt_given_Q_should_remove_Q(void)

{

 int removedChar;

 String *str = stringNew("Q");

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((81)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

}









void test_stringCharAt_given_Bone_should_remove_B(void)

{

 int removedChar;

 String *str = stringNew("Bone");

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

}









void test_stringCharAt_given_Pig_and_removex2_should_remove_i(void)

{

 int removedChar;

 String *str = stringNew("Pig");

 removedChar = stringRemoveChar(str);

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((105)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)405, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)406, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)407, UNITY_DISPLAY_STYLE_INT);

}











void test_stringSkip_given_TED_and_skip_1_char_should_skip_T(void)

{

 String *str = stringNew("TED");

 stringSkip(str , 1);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)419, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)420, UNITY_DISPLAY_STYLE_INT);

}











void test_stringSkip_given_Angel_and_skip_5_char_should_skip_all_character(void)

{

 String *str = stringNew("Angel");

 stringSkip(str , 5);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->string[str->startindex])), (((void *)0)), (_U_UINT)432, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)433, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)434, UNITY_DISPLAY_STYLE_INT);

}











void test_stringSkip_given_Monalisa_and_skip_negative_two_char_should_skip_nothing(void)

{

 String *str = stringNew("Monalisa");

 stringSkip(str , -2);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)446, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)447, UNITY_DISPLAY_STYLE_INT);

}











void test_stringSkip_given_Miracle_and_skip_10_char_should_skip_all_character_and_stop_at_position_7(void)

{

 String *str = stringNew("Miracle");

 stringSkip(str , 10);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->string[str->startindex])), (((void *)0)), (_U_UINT)459, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)460, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)461, UNITY_DISPLAY_STYLE_INT);

}









void test_stringSubStringInChars_given_82_plus_29_and_length_is_2_should_return_82(void)

{

 char *subString;

 String *str = stringNew("82+29");

 subString = stringSubStringInChars(str , 2);



 UnityAssertEqualString((const char*)("82"), (const char*)(subString), (((void *)0)), (_U_UINT)473);

}









void test_stringSubStringInChars_given_negative_234_times_1_and_length_is_5_should_return_negative_234_space(void)

{

 char *subString;

 String *str = stringNew("-234 * 1");

 subString = stringSubStringInChars(str , 5);



 UnityAssertEqualString((const char*)("-234 "), (const char*)(subString), (((void *)0)), (_U_UINT)485);

}









void test_subStringToInteger_given_149_minus_20_should_return_149_in_integer(void)

{

 char *subString;

 int integer;

 String *str = stringNew("149-20");

 subString = stringSubStringInChars(str , 3);

 integer = subStringToInteger(str , subString);



 UnityAssertEqualString((const char*)("149"), (const char*)(subString), (((void *)0)), (_U_UINT)499);

 UnityAssertEqualNumber((_U_SINT)((149)), (_U_SINT)((integer)), (((void *)0)), (_U_UINT)500, UNITY_DISPLAY_STYLE_INT);

}
