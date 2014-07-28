/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_stringNew_given_NEW_startindex_0_and_length_0(void);
extern void test_stringTrimLeft_should_skip_spaces_on_left_sides_0(void);
extern void test_stringTrimLeft_should_skip_spaces_on_left_sides_1(void);
extern void test_stringTrimLeft_should_skip_spaces_on_left_sides_2(void);
extern void test_stringTrimRight_should_skip_spaces_on_left_sides_0(void);
extern void test_stringTrimRight_should_skip_spaces_on_left_sides_str_length_will_remain_same_when_i_call_trim_right_x2(void);
extern void test_stringTrimRight_should_skip_spaces_on_left_sides_2(void);
extern void test_stringTrim_should_skip_spaces_on_left_and_right_sides_0(void);
extern void test_stringTrim_should_skip_spaces_on_left_and_right_sides_1(void);
extern void test_stringTrim_should_skip_spaces_on_left_and_right_sides_2(void);
extern void test_stringRemoveWordContaining_given_HELLO_should_remove_L(void);
extern void test_stringRemoveWordContaining_MAXIS_should_remove_A(void);
extern void test_stringRemoveWordContaining_space_tab_21_plus_32_space_tab_should_remove_21(void);
extern void test_stringRemoveWordContaining_tab_space_negative_10_plus_2_space_should_remove_10(void);
extern void test_stringRemoveWordContaining_tab_AB_plus_CD_tab_should_remove_nothing(void);
extern void test_stringRemoveWordContaining_Beef_and_call_stringRemoveWordContaining_x2_should_nothing(void);
extern void test_stringRemoveWordContaining_123_plus_65_times_91_should_remove_nothing(void);
extern void test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC(void);
extern void test_stringRemoveWordNotContaining_Jel_apostrophe_ly_should_remove_Jel(void);
extern void test_stringRemoveWordNotContaining_Lady_square_bracket_should_remove_square_bracket(void);
extern void test_stringRemoveWordNotContaining_Oil_comma_should_remove_Oil_comma(void);
extern void test_stringCharAt_given_Apple_and_relative_position_1_should_return_p(void);
extern void test_stringCharAt_given_Orange_and_relative_position_6_should_return_negative_1(void);
extern void test_stringCharAt_given_2_plus_3_and_relative_position_negative_five_should_return_negative_1(void);
extern void test_stringCharAt_given_Q_should_remove_Q(void);
extern void test_stringCharAt_given_Bone_should_remove_B(void);
extern void test_stringCharAt_given_Pig_and_removex2_should_remove_i(void);
extern void test_stringSkip_given_TED_and_skip_1_char_should_skip_T(void);
extern void test_stringSkip_given_Error_and_skip_4_char_should_skip_Erro(void);
extern void test_stringSkip_given_Angel_and_skip_5_char_should_skip_all_character(void);
extern void test_stringSkip_given_Monalisa_and_skip_negative_two_char_should_skip_nothing(void);
extern void test_stringSkip_given_Miracle_and_skip_10_char_should_skip_all_character_and_stop_at_position_7(void);
extern void test_stringSubStringInChars_given_82_plus_29_and_length_is_2_should_return_82(void);
extern void test_stringSubStringInChars_given_40_times_5_length_is_2_and_call_subString_x2_should_return_times_5(void);
extern void test_stringSubStringInChars_given_65_times_160_length_is_6_and_call_subString_x2_should_return_nothing(void);
extern void test_stringSubStringInChars_given_negative_234_times_1_and_length_is_5_should_return_negative_234_space(void);
extern void test_stringSubStringInChars_given_20_divide_5_skip_3_chars_and_length_is_1_should_return_5(void);
extern void test_stringSubStringInChars_given_12_plus_34_times_67_skip_4_chars_and_length_is_4_should_return_9_times_67(void);
extern void test_subStringToInteger_given_149_should_return_149_in_integer(void);
extern void test_subStringToInteger_given_negative_50_should_return_negative_50_in_integer(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_StringObject.c";
  UnityBegin();
  RUN_TEST(test_stringNew_given_NEW_startindex_0_and_length_0, 16);
  RUN_TEST(test_stringTrimLeft_should_skip_spaces_on_left_sides_0, 30);
  RUN_TEST(test_stringTrimLeft_should_skip_spaces_on_left_sides_1, 44);
  RUN_TEST(test_stringTrimLeft_should_skip_spaces_on_left_sides_2, 58);
  RUN_TEST(test_stringTrimRight_should_skip_spaces_on_left_sides_0, 72);
  RUN_TEST(test_stringTrimRight_should_skip_spaces_on_left_sides_str_length_will_remain_same_when_i_call_trim_right_x2, 87);
  RUN_TEST(test_stringTrimRight_should_skip_spaces_on_left_sides_2, 101);
  RUN_TEST(test_stringTrim_should_skip_spaces_on_left_and_right_sides_0, 115);
  RUN_TEST(test_stringTrim_should_skip_spaces_on_left_and_right_sides_1, 129);
  RUN_TEST(test_stringTrim_should_skip_spaces_on_left_and_right_sides_2, 143);
  RUN_TEST(test_stringRemoveWordContaining_given_HELLO_should_remove_L, 157);
  RUN_TEST(test_stringRemoveWordContaining_MAXIS_should_remove_A, 177);
  RUN_TEST(test_stringRemoveWordContaining_space_tab_21_plus_32_space_tab_should_remove_21, 198);
  RUN_TEST(test_stringRemoveWordContaining_tab_space_negative_10_plus_2_space_should_remove_10, 220);
  RUN_TEST(test_stringRemoveWordContaining_tab_AB_plus_CD_tab_should_remove_nothing, 241);
  RUN_TEST(test_stringRemoveWordContaining_Beef_and_call_stringRemoveWordContaining_x2_should_nothing, 262);
  RUN_TEST(test_stringRemoveWordContaining_123_plus_65_times_91_should_remove_nothing, 285);
  RUN_TEST(test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC, 312);
  RUN_TEST(test_stringRemoveWordNotContaining_Jel_apostrophe_ly_should_remove_Jel, 333);
  RUN_TEST(test_stringRemoveWordNotContaining_Lady_square_bracket_should_remove_square_bracket, 354);
  RUN_TEST(test_stringRemoveWordNotContaining_Oil_comma_should_remove_Oil_comma, 375);
  RUN_TEST(test_stringCharAt_given_Apple_and_relative_position_1_should_return_p, 396);
  RUN_TEST(test_stringCharAt_given_Orange_and_relative_position_6_should_return_negative_1, 412);
  RUN_TEST(test_stringCharAt_given_2_plus_3_and_relative_position_negative_five_should_return_negative_1, 428);
  RUN_TEST(test_stringCharAt_given_Q_should_remove_Q, 443);
  RUN_TEST(test_stringCharAt_given_Bone_should_remove_B, 460);
  RUN_TEST(test_stringCharAt_given_Pig_and_removex2_should_remove_i, 477);
  RUN_TEST(test_stringSkip_given_TED_and_skip_1_char_should_skip_T, 496);
  RUN_TEST(test_stringSkip_given_Error_and_skip_4_char_should_skip_Erro, 511);
  RUN_TEST(test_stringSkip_given_Angel_and_skip_5_char_should_skip_all_character, 526);
  RUN_TEST(test_stringSkip_given_Monalisa_and_skip_negative_two_char_should_skip_nothing, 542);
  RUN_TEST(test_stringSkip_given_Miracle_and_skip_10_char_should_skip_all_character_and_stop_at_position_7, 557);
  RUN_TEST(test_stringSubStringInChars_given_82_plus_29_and_length_is_2_should_return_82, 572);
  RUN_TEST(test_stringSubStringInChars_given_40_times_5_length_is_2_and_call_subString_x2_should_return_times_5, 589);
  RUN_TEST(test_stringSubStringInChars_given_65_times_160_length_is_6_and_call_subString_x2_should_return_nothing, 607);
  RUN_TEST(test_stringSubStringInChars_given_negative_234_times_1_and_length_is_5_should_return_negative_234_space, 625);
  RUN_TEST(test_stringSubStringInChars_given_20_divide_5_skip_3_chars_and_length_is_1_should_return_5, 640);
  RUN_TEST(test_stringSubStringInChars_given_12_plus_34_times_67_skip_4_chars_and_length_is_4_should_return_9_times_67, 656);
  RUN_TEST(test_subStringToInteger_given_149_should_return_149_in_integer, 672);
  RUN_TEST(test_subStringToInteger_given_negative_50_should_return_negative_50_in_integer, 683);

  return (UnityEnd());
}
