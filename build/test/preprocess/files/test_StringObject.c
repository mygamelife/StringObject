#include "unity.h"
#include "StringObject.h"


void setUp(void)

{

}



void tearDown(void)

{

}









void test_stringNew_given_NEW_startindex_0_and_length_0(void)

{

 String *str = stringNew("NEW");



 UnityAssertEqualString((const char*)("NEW"), (const char*)(str->string), (((void *)0)), (_U_UINT)20);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_0(void)

{

 String *str = stringNew(" 2+2");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_1(void)

{

 String *str = stringNew("\t\tABC");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrimLeft_should_skip_spaces_on_left_sides_2(void)

{

 String *str = stringNew("\t  C \tHAOS");

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrimRight_should_skip_spaces_on_left_sides_0(void)

{

 String *str = stringNew("SLEEPLY ");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringTrimRight_should_skip_spaces_on_left_sides_str_length_will_remain_same_when_i_call_trim_right_x2(void)

{

 String *str = stringNew("  DRY    ");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrimRight_should_skip_spaces_on_left_sides_2(void)

{

 String *str = stringNew("\t\tLO VE\t\t");

 stringTrimRight(str);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_0(void)

{

 String *str = stringNew(" Stress ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_1(void)

{

 String *str = stringNew("  2 +6 ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringTrim_should_skip_spaces_on_left_and_right_sides_2(void)

{

 String *str = stringNew("\t \t 13 +20 \t \t ");

 stringTrim(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringRemoveWordContaining_given_HELLO_should_remove_L(void)

{

 String *str = stringNew(" HELLO");

 String *result;

 stringTrim(str);

 result = stringRemoveWordContaining(str , "L");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringRemoveWordContaining_MAXIS_should_remove_A(void)

{

 String *str = stringNew("MAXIS");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "AI");





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordContaining_space_tab_21_plus_32_space_tab_should_remove_21(void)

{

 String *str = stringNew(" \t 21 + 32  \t ");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "01234");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}













void test_stringRemoveWordContaining_tab_space_negative_10_plus_2_space_should_remove_10(void)

{

 String *str = stringNew("\t -10 + 2 ");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "43210");





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordContaining_tab_AB_plus_CD_tab_should_remove_nothing(void)

{

 String *str = stringNew("\tAB + CD\t");

 stringTrim(str);

 String *result;

 result = stringRemoveWordContaining(str , "+");





 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordContaining_Beef_and_call_stringRemoveWordContaining_x2_should_nothing(void)

{

 String *str = stringNew(" Beef ");

 String *result;

 stringTrim(str);

 result = stringRemoveWordContaining(str , "f");

 stringTrim(str);

 result = stringRemoveWordContaining(str , "f");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)275, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordContaining_123_plus_65_times_91_should_remove_nothing(void)

{

 String *str = stringNew(" 123 + 65 * 91 ");

 String *result;

 stringTrim(str);

 result = stringRemoveWordContaining(str , "0123456789");

 stringTrim(str);

 result = stringRemoveWordContaining(str , "0123456789");

 stringTrim(str);

 result = stringRemoveWordContaining(str , "0123456789");

 stringTrim(str);

 result = stringRemoveWordContaining(str , "0123456789");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)302, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC(void)

{

 String *str = stringNew(",ABC");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "A");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)320, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)321, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)323, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordNotContaining_Jel_apostrophe_ly_should_remove_Jel(void)

{

 String *str = stringNew("Jel'ly");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "'");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)342, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordNotContaining_Lady_square_bracket_should_remove_square_bracket(void)

{

 String *str = stringNew("Lady[]");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , "[]");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringRemoveWordNotContaining_Oil_comma_should_remove_Oil_comma(void)

{

 String *str = stringNew("Oil,");

 stringTrim(str);

 String *result;

 result = stringRemoveWordNotContaining(str , ";'[");





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->startindex)), (((void *)0)), (_U_UINT)383, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((result->length)), (((void *)0)), (_U_UINT)384, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)386, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringCharAt_given_Apple_and_relative_position_1_should_return_p(void)

{

 int charAtThisPosition;

 String *str = stringNew("Apple");

 charAtThisPosition = stringCharAt(str , 1);





 UnityAssertEqualNumber((_U_SINT)((112)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)403, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringCharAt_given_Orange_and_relative_position_6_should_return_negative_1(void)

{

 int charAtThisPosition;

 String *str = stringNew("Orange");

 charAtThisPosition = stringCharAt(str , 6);





 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)419, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringCharAt_given_2_plus_3_and_relative_position_negative_five_should_return_negative_1(void)

{

 int charAtThisPosition;

 String *str = stringNew("2+3");

 charAtThisPosition = stringCharAt(str , -5);





 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((charAtThisPosition)), (((void *)0)), (_U_UINT)435, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringCharAt_given_Q_should_remove_Q(void)

{

 int removedChar;

 String *str = stringNew("Q");

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((81)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)452, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringCharAt_given_Bone_should_remove_B(void)

{

 int removedChar;

 String *str = stringNew("Bone");

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)467, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)468, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)469, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringCharAt_given_Pig_and_removex2_should_remove_i(void)

{

 int removedChar;

 String *str = stringNew("Pig");

 removedChar = stringRemoveChar(str);

 removedChar = stringRemoveChar(str);





 UnityAssertEqualNumber((_U_SINT)((105)), (_U_SINT)((removedChar)), (((void *)0)), (_U_UINT)485, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)487, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringSkip_given_TED_and_skip_1_char_should_skip_T(void)

{

 String *str = stringNew("TED");

 stringSkip(str , 1);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)501, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)502, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringSkip_given_Error_and_skip_4_char_should_skip_Erro(void)

{

 String *str = stringNew("Error");

 stringSkip(str , 4);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)516, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)517, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringSkip_given_Angel_and_skip_5_char_should_skip_all_character(void)

{

 String *str = stringNew("Angel");

 stringSkip(str , 5);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->string[str->startindex])), (((void *)0)), (_U_UINT)531, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)532, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)533, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringSkip_given_Monalisa_and_skip_negative_two_char_should_skip_nothing(void)

{

 String *str = stringNew("Monalisa");

 stringSkip(str , -2);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)547, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)548, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}











void test_stringSkip_given_Miracle_and_skip_10_char_should_skip_all_character_and_stop_at_position_7(void)

{

 String *str = stringNew("Miracle");

 stringSkip(str , 10);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->string[str->startindex])), (((void *)0)), (_U_UINT)562, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)563, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)564, UNITY_DISPLAY_STYLE_INT);



 stringDel(str);

}









void test_stringSubStringInChars_given_82_plus_29_and_length_is_2_should_return_82(void)

{

 char *subString;

 String *str = stringNew("82+29");

 subString = stringSubStringInChars(str , 2);



 UnityAssertEqualString((const char*)("82"), (const char*)(subString), (((void *)0)), (_U_UINT)578);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)579, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)580, UNITY_DISPLAY_STYLE_INT);



 subStringDel(subString);

 stringDel(str);

}









void test_stringSubStringInChars_given_40_times_5_length_is_2_and_call_subString_x2_should_return_times_5(void)

{

 char *subString;

 String *str = stringNew("40*5");

 subString = stringSubStringInChars(str , 2);

 subString = stringSubStringInChars(str , 2);



 UnityAssertEqualString((const char*)("*5"), (const char*)(subString), (((void *)0)), (_U_UINT)596);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)597, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)598, UNITY_DISPLAY_STYLE_INT);



 subStringDel(subString);

 stringDel(str);

}









void test_stringSubStringInChars_given_65_times_160_length_is_6_and_call_subString_x2_should_return_nothing(void)

{

 char *subString;

 String *str = stringNew("65*160");

 subString = stringSubStringInChars(str , 6);

 subString = stringSubStringInChars(str , 6);



 UnityAssertEqualString((const char*)(""), (const char*)(subString), (((void *)0)), (_U_UINT)614);

 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((str->startindex)), (((void *)0)), (_U_UINT)615, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)616, UNITY_DISPLAY_STYLE_INT);



 subStringDel(subString);

 stringDel(str);

}









void test_stringSubStringInChars_given_negative_234_times_1_and_length_is_5_should_return_negative_234_space(void)

{

 char *subString;

 String *str = stringNew("-234 * 1");

 subString = stringSubStringInChars(str , 5);



 UnityAssertEqualString((const char*)("-234 "), (const char*)(subString), (((void *)0)), (_U_UINT)631);



 subStringDel(subString);

 stringDel(str);

}









void test_stringSubStringInChars_given_20_divide_5_skip_3_chars_and_length_is_1_should_return_5(void)

{

 char *subString;

 String *str = stringNew("20/5");

 stringSkip(str , 3);

 subString = stringSubStringInChars(str , 1);



 UnityAssertEqualString((const char*)("5"), (const char*)(subString), (((void *)0)), (_U_UINT)647);



 subStringDel(subString);

 stringDel(str);

}









void test_stringSubStringInChars_given_12_plus_34_times_67_skip_4_chars_and_length_is_4_should_return_9_times_67(void)

{

 char *subString;

 String *str = stringNew("12+34*67");

 stringSkip(str , 4);

 subString = stringSubStringInChars(str , 4);



 UnityAssertEqualString((const char*)("4*67"), (const char*)(subString), (((void *)0)), (_U_UINT)663);



 subStringDel(subString);

 stringDel(str);

}









void test_subStringToInteger_given_149_should_return_149_in_integer(void)

{

 char *number = "149";

 int integer = subStringToInteger(number);



 UnityAssertEqualNumber((_U_SINT)((149)), (_U_SINT)((integer)), (((void *)0)), (_U_UINT)677, UNITY_DISPLAY_STYLE_INT);

}









void test_subStringToInteger_given_negative_50_should_return_negative_50_in_integer(void)

{

 char *number = "-50";

 int integer = subStringToInteger(number);



 UnityAssertEqualNumber((_U_SINT)((-50)), (_U_SINT)((integer)), (((void *)0)), (_U_UINT)688, UNITY_DISPLAY_STYLE_INT);

}
