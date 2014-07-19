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