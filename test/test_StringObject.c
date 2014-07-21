#include "unity.h"
#include "StringObject.h"
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

/*#1
 * Create a new String
 */ 
void test_stringNewX_given_NEW_startindex_0_and_length_0(void)
{
	String *str = stringNew("NEW");
	
	TEST_ASSERT_EQUAL_STRING("NEW" , str->string);
	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#2
 * Trim all the spaces from left and stop at non-spaces character
 */
void test_stringTrimLeft_should_skip_spaces_on_left_sides_0(void)
{
	String *str = stringNew(" 2+2");
	stringTrimLeft(str);
	
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(4 , str->length);
}

/*#3
 * Trim all the spaces included \t from left and stop at non-spaces character
 */
void test_stringTrimLeft_should_skip_spaces_on_left_sides_1(void)
{
	String *str = stringNew("\t\tABC");
	stringTrimLeft(str);
	
	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(5 , str->length);
}

/*#4
 * Trim all the spaces included \t from left and character is between spaces
 */
void test_stringTrimLeft_should_skip_spaces_on_left_sides_2(void)
{
	String *str = stringNew("\t  C \tHAOS");
	stringTrimLeft(str);
	
	TEST_ASSERT_EQUAL(3 , str->startindex);
	TEST_ASSERT_EQUAL(10 , str->length);
}

/*#5
 * Trim all the spaces from right
 */
void test_stringTrimRight_should_skip_spaces_on_left_sides_0(void)
{
	String *str = stringNew("SLEEPLY ");
	stringTrimRight(str);

	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(7 , str->length);
}

/*#6
 * Trim all the spaces on right side of the string and don't care the spaces on left side
 */
void test_stringTrimRight_should_skip_spaces_on_left_sides_1(void)
{
	String *str = stringNew("  DRY ");
	stringTrimRight(str);
	
	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(5 , str->length);
}

/*#7
 * Trim all the spaces on right side included \t and don't care the spaces in between character
 */
void test_stringTrimRight_should_skip_spaces_on_left_sides_2(void)
{
	String *str = stringNew("\t\tLO VE\t\t");
	stringTrimRight(str);
	
	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(7 , str->length);
}

/*#8
 * Trim spaces on left and right of the string
 */
void test_stringTrim_should_skip_spaces_on_left_and_right_sides_0(void)
{
	String *str = stringNew(" Stress ");
	stringTrim(str);
		
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(7 , str->length);
}

/*#9
 * Trim spaces on left and right of the string and don't trim spaces in middle of string
 */
void test_stringTrim_should_skip_spaces_on_left_and_right_sides_1(void)
{
	String *str = stringNew("  2 +6 "); 
	stringTrim(str);

	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(6 , str->length);
}

/*#10
 * Trim spaces on left and right of the string (Included \t tab) and don't trim spaces in middle of string
 */
void test_stringTrim_should_skip_spaces_on_left_and_right_sides_2(void)
{
	String *str = stringNew("\t \t 13 +20 \t \t "); 
	stringTrim(str);

	TEST_ASSERT_EQUAL(4 , str->startindex);
	TEST_ASSERT_EQUAL(10 , str->length);
}

/*#11
 * Given " HELLO" and containSet "L" should remove two LL 
 */
void test_stringRemoveWordContaining_given_HELLO_should_remove_L(void)
{
	String *str = stringNew(" HELLO");
	stringTrim(str);
	String *result;
	result = stringRemoveWordContaining(str , "L");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(3 , result->startindex);
	TEST_ASSERT_EQUAL(2 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(1 , str->length);
}

/*#12
 * Given "MAXIS" and containSet "AI" should remove A and stop at X since X not inside containSet
 */ 
void test_stringRemoveWordContaining_MAXIS_should_remove_A(void)
{
	String *str = stringNew("MAXIS");
	stringTrim(str);
	String *result;	
	result = stringRemoveWordContaining(str , "AI");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(1 , result->startindex);
	TEST_ASSERT_EQUAL(1 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#13
 * Given " Beef " and containSet "f" should stop at f
 * str->start index is next to f and length is 0
 */
void test_stringRemoveWordContaining_Beef_should_remove_f(void)
{	
	String *str = stringNew(" Beef ");
	stringTrim(str);
	String *result;
	result = stringRemoveWordContaining(str , "f");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(4 , result->startindex);
	TEST_ASSERT_EQUAL(1 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#14
 * given " \t 21 + 32  \t " and containSet "01234"
 * 21 will be remove and str->startindex stop at position next to 21 which is space
 */
void test_stringRemoveWordContaining_space_tab_21_plus_32_space_tab_should_remove_21(void)
{
	String *str = stringNew(" \t 21 + 32  \t ");
	stringTrim(str);
	String *result;
	result = stringRemoveWordContaining(str , "01234");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(3 , result->startindex);
	TEST_ASSERT_EQUAL(2 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(5 , str->length);
}

/*#15
 * given "\t -10 + 2 " and containSet "43210"
 * skip negative sign
 * 10 will be remove and str->startindex stop at position next to 10 which is space
 */
void test_stringRemoveWordContaining_tab_space_negative_10_plus_2_space_should_remove_10(void)
{
	String *str = stringNew("\t -10 + 2 ");
	stringTrim(str);
	String *result;
	result = stringRemoveWordContaining(str , "43210");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(3 , result->startindex);
	TEST_ASSERT_EQUAL(2 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(4 , str->length);
}

/*#16
 * given "\tAB + CD\t" and containSet "XYZ"
 * ABCD not inside containSet therefore remove nothing
 */
void test_stringRemoveWordContaining_tab_AB_plus_CD_tab_should_remove_nothing(void)
{
	String *str = stringNew("\tAB + CD\t");
	stringTrim(str);
	String *result;
	result = stringRemoveWordContaining(str , "XYZ");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(0 , result->startindex);
	TEST_ASSERT_EQUAL(0 , result->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(8 , str->length);
}

/*#17
 * Given ",ABC" and notContainSet "A"
 * Should remove comma "," and stop at A because A contain in notContainSet
*/
void test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC(void)
{
	String *str = stringNew(",ABC");
	stringTrim(str);
	String *result;
	result = stringRemoveWordNotContaining(str , "A");
	
	/*Removed string from not containing in notContainSet*/
	TEST_ASSERT_EQUAL(0 , result->startindex);
	TEST_ASSERT_EQUAL(1 , result->length);
	/*String contain in notContainSet*/
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#18
 * Given "Jel'ly" and notContainSet "'"
 * Should remove "Jel" and stop at apostrophe ' because ' contain in notContainSet
*/
void test_stringRemoveWordNotContaining_Jel_apostrophe_ly_should_remove_Jel(void)
{
	String *str = stringNew("Jel'ly");
	stringTrim(str);
	String *result;
	result = stringRemoveWordNotContaining(str , "'");
	
	/*Removed string from not containing in notContainSet*/
	TEST_ASSERT_EQUAL(0 , result->startindex);
	TEST_ASSERT_EQUAL(3 , result->length);
	/*String contain in notContainSet*/
	TEST_ASSERT_EQUAL(3 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#19
 * Given "Lady[]" and notContainSet "[]"
 * Should remove "Lady" and stop at square bracket [ because [ contain in notContainSet
*/
void test_stringRemoveWordNotContaining_Lady_square_bracket_should_remove_square_bracket(void)
{
	String *str = stringNew("Lady[]");
	stringTrim(str);
	String *result;
	result = stringRemoveWordNotContaining(str , "[]");
	
	/*Removed string from not containing in notContainSet*/
	TEST_ASSERT_EQUAL(0 , result->startindex);
	TEST_ASSERT_EQUAL(6 , result->length);
	/*String contain in notContainSet*/
	TEST_ASSERT_EQUAL(6 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#20
 * Given "Oil," and notContainSet ";'["
 * Should remove all because all words not contain inside notContainSet
*/
void test_stringRemoveWordNotContaining_Oil_comma_should_remove_Oil_comma(void)
{
	String *str = stringNew("Oil,");
	stringTrim(str);
	String *result;
	result = stringRemoveWordNotContaining(str , ";'[");
	
	/*Removed string from not containing in notContainSet*/
	TEST_ASSERT_EQUAL(0 , result->startindex);
	TEST_ASSERT_EQUAL(4 , result->length);
	/*String contain in notContainSet*/
	TEST_ASSERT_EQUAL(4 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#21
 * Given string "Apple" and relativePos 1
 * Should return the relative position character "p"
 */
void test_stringCharAt_given_Apple_and_relative_position_1_should_return_p(void)
{
	int charAtThisPosition;
	String *str = stringNew("Apple");
	charAtThisPosition = stringCharAt(str , 1);
	
	/* p = 112 in ASCII table */
	TEST_ASSERT_EQUAL(112 , charAtThisPosition);
}

/*#22
 * Given string "Orange" and relativePos 6
 * Should return -1
 */
void test_stringCharAt_given_Orange_and_relative_position_6_should_return_negative_1(void)
{
	int charAtThisPosition;
	String *str = stringNew("Orange");
	charAtThisPosition = stringCharAt(str , 6);
	
	/* position 6 is beyond the position "e" */
	TEST_ASSERT_EQUAL(-1 , charAtThisPosition);
}

/*#23
 * Given string "2+3" and relativePos -5
 * Should return -1
 */
void test_stringCharAt_given_2_plus_3_and_relative_position_negative_five_should_return_negative_1(void)
{
	int charAtThisPosition;
	String *str = stringNew("2+3");
	charAtThisPosition = stringCharAt(str , -5);
	
	/* -5 is not a valid position inside the string */
	TEST_ASSERT_EQUAL(-1 , charAtThisPosition);
}

/*#24
 * Given string "Q" and should remove only one character "Q" and startindex 1 and length is 0
 */
void test_stringCharAt_given_Q_should_remove_Q(void)
{
	int removedChar;
	String *str = stringNew("Q");
	removedChar = stringRemoveChar(str);
	
	/* Q = 81 in ASCII table */
	TEST_ASSERT_EQUAL(81 , removedChar);
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#25
 * Given string "Bone" and should remove character "B" and startindex 1 and length is 3
 */
void test_stringCharAt_given_Bone_should_remove_B(void)
{
	int removedChar;
	String *str = stringNew("Bone");
	removedChar = stringRemoveChar(str);
	
	/* B = 66 in ASCII table */
	TEST_ASSERT_EQUAL(66 , removedChar);
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#26
 * Given string "Pig" remove 2 times startindex = 2 & length = 1
 */
void test_stringCharAt_given_Pig_and_removex2_should_remove_i(void)
{
	int removedChar;
	String *str = stringNew("Pig");
	removedChar = stringRemoveChar(str);
	removedChar = stringRemoveChar(str);
	
	/* i = 105 in ASCII table */
	TEST_ASSERT_EQUAL(105 , removedChar);
	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(1 , str->length);
}

/*#27
 * Given string "TED" and number of character to skip is 1 
 * Should skip "T" and remain "ED"
 */
void test_stringSkip_given_TED_and_skip_1_char_should_skip_T(void)
{
	String *str = stringNew("TED");
	stringSkip(str , 1);
	
	TEST_ASSERT_EQUAL(1 , str->startindex);
	TEST_ASSERT_EQUAL(2 , str->length);
}

/*#28
 * Given string "Error" and number of character to skip is 4 
 * Should skip "Erro" and remain "r"
 */
void test_stringSkip_given_Error_and_skip_4_char_should_skip_Erro(void)
{
	String *str = stringNew("Error");
	stringSkip(str , 4);
	
	TEST_ASSERT_EQUAL(4 , str->startindex);
	TEST_ASSERT_EQUAL(1 , str->length);
}

/*#29
 * Given string "Angel" and number of character to skip is 5 
 * Should skip "Angel" and remain nothing
 */
void test_stringSkip_given_Angel_and_skip_5_char_should_skip_all_character(void)
{
	String *str = stringNew("Angel");
	stringSkip(str , 5);
	
	TEST_ASSERT_EQUAL(0 , str->string[str->startindex]);
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#30
 * Given string "Monalisa" and number of character to skip is -2 
 * Should skip nothing
 */
void test_stringSkip_given_Monalisa_and_skip_negative_two_char_should_skip_nothing(void)
{
	String *str = stringNew("Monalisa");
	stringSkip(str , -2);
	
	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(8 , str->length);
}

/*#31
 * Given string "Miracle" and number of character to skip is 10 
 * Should skip all character and startindex pointing at 5
 */
void test_stringSkip_given_Miracle_and_skip_10_char_should_skip_all_character_and_stop_at_position_7(void)
{
	String *str = stringNew("Miracle");
	stringSkip(str , 10);
	
	TEST_ASSERT_EQUAL(0 , str->string[str->startindex]);
	TEST_ASSERT_EQUAL(7 , str->startindex);
	TEST_ASSERT_EQUAL(0 , str->length);
}

/*#32
 * Given "82+29" and length is 2 should remove "82" as a substring
 */
void test_stringSubStringInChars_given_82_plus_29_and_length_is_2_should_return_82(void)
{
	char *subString;
	String *str = stringNew("82+29");
	subString = stringSubStringInChars(str , 2);
	
	TEST_ASSERT_EQUAL_STRING("82" , subString);
}

/*#33
 * Given "-234 * 1" and length is 2 should remove "-234 " as a substring
 */
void test_stringSubStringInChars_given_negative_234_times_1_and_length_is_5_should_return_negative_234_space(void)
{
	char *subString;
	String *str = stringNew("-234 * 1");
	subString = stringSubStringInChars(str , 5);
	
	TEST_ASSERT_EQUAL_STRING("-234 " , subString);
}

/*#34
 * Given "20/5" skip 3 characters and take the remaining character "5" as substring
 */
void test_stringSubStringInChars_given_20_divide_5_skip_3_chars_and_length_is_1_should_return_5(void)
{
	char *subString;
	String *str = stringNew("20/5");
	stringSkip(str , 3);
	subString = stringSubStringInChars(str , 1);
	
	TEST_ASSERT_EQUAL_STRING("5" , subString);
}

/*#35
 * Given "12+34*67" skip 4 characters and take the remaining character "4*67" as substring
 */
void test_stringSubStringInChars_given_12_plus_34_times_67_skip_4_chars_and_length_is_4_should_return_9_times_67(void)
{
	char *subString;
	String *str = stringNew("12+34*67");
	stringSkip(str , 4);
	subString = stringSubStringInChars(str , 4);
	
	TEST_ASSERT_EQUAL_STRING("4*67" , subString);
}

/*#36
 * Given "149" should return 149 as a integer
 */
void test_subStringToInteger_given_149_should_return_149_in_integer(void)
{
	char *number = "149";
	int integer = subStringToInteger(number);

	TEST_ASSERT_EQUAL(149 , integer);
}

/*#37
 * Given "-50" should return 149 as a integer
 */
void test_subStringToInteger_given_negative_50_should_return_negative_50_in_integer(void)
{
	char *number = "-50";
	int integer = subStringToInteger(number);

	TEST_ASSERT_EQUAL(-50 , integer);
}