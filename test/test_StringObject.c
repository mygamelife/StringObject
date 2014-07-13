#include "unity.h"
#include "StringObject.h"
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

/*#1*/ void test_StringTrim_should_skip_spaces_in_left_sides_and_store_in_strStrings(void)
{
	Strings *str = stringNew();
	StringTrim(str , " 2+2");
	
	TEST_ASSERT_EQUAL(3 , strlen(str->strings));
}

/*#2*/ void test_StringTrim_should_skip_spaces_in_right_sides_and_store_in_strStrings(void)
{
	Strings *str = stringNew();
	StringTrim(str , "4+8+1  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#3*/ void test_StringTrim_should_skip_all_spaces_and_store_in_strStrings(void)
{
	Strings *str = stringNew();
	StringTrim(str , " 4 - 2 +   3  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#4*/ void test_stringRemoveWordContaining_given_HELLO_should_remove_L(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , "HELLO");
	removedWord = stringRemoveWordContaining(str , "L");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(2 , removedWord->startindex);
	TEST_ASSERT_EQUAL(2 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(4 , str->startindex);
	TEST_ASSERT_EQUAL(1 , str->length);
}

/*#5*/ void test_stringRemoveWordContaining_MAXIS_should_remove_A(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , "MAXIS");
	removedWord = stringRemoveWordContaining(str , "AI");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(1 , removedWord->startindex);
	TEST_ASSERT_EQUAL(1 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#6*/ void test_stringRemoveWordContaining_LECTURE_should_remove_CTU(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , "LECTURE");
	removedWord = stringRemoveWordContaining(str , "UTC");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(2 , removedWord->startindex);
	TEST_ASSERT_EQUAL(3 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(5 , str->startindex);
	TEST_ASSERT_EQUAL(2 , str->length);
}

/*#7*/ void test_stringRemoveWordContaining_321_plus_432_should_remove_321(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , "321 + 432 ");
	removedWord = stringRemoveWordContaining(str , "01234");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(0 , removedWord->startindex);
	TEST_ASSERT_EQUAL(3 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(3 , str->startindex);
	TEST_ASSERT_EQUAL(4 , str->length);
}

/*#8*/ void test_stringRemoveWordContaining_89_plus_40_minus_2_should_remove_plus(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , " 8 9 +40  - 2 ");
	removedWord = stringRemoveWordContaining(str , "+-*/");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(2 , removedWord->startindex);
	TEST_ASSERT_EQUAL(1 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(3 , str->startindex);
	TEST_ASSERT_EQUAL(4 , str->length);
}

/*#9*/ void test_stringRemoveWordNotContaining_comma_ABC_comma_should_remove_ABC(void)
{
	Strings *removedWord;
	Strings *str = stringNew();
	StringTrim(str , ",ABC");
	removedWord = stringRemoveWordNotContaining(str , ",");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(1 , removedWord->startindex);
	TEST_ASSERT_EQUAL(3 , removedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(0 , str->startindex);
	TEST_ASSERT_EQUAL(1 , str->length);
}
