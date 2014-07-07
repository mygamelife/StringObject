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
	Strings *str = StringNew();
	StringTrim(str , " 2+2");
	
	TEST_ASSERT_EQUAL(3 , strlen(str->strings));
}

/*#2*/ void test_StringTrim_should_skip_spaces_in_right_sides_and_store_in_strStrings(void)
{
	Strings *str = StringNew();
	StringTrim(str , "4+8+1  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#3*/ void test_StringTrim_should_skip_all_spaces_and_store_in_strStrings(void)
{
	Strings *str = StringNew();
	StringTrim(str , " 4 - 2 +   3  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#4*/ void test_StringRemoveWordContaining_given_HELLO_should_remove_Lx2(void)
{
	Strings *RemovedWord;
	Strings *str = StringNew();
	StringTrim(str , "HELLO");
	RemovedWord = StringRemoveWordContaining(str , "L");
	
	/*Removed String*/
	TEST_ASSERT_EQUAL(2 , RemovedWord->startindex);
	TEST_ASSERT_EQUAL(2 , RemovedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(4 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}

/*#5*/ void test_StringRemoveWordContaining_MAXIS_should_remove_A_and_I(void)
{
	Strings *RemovedWord;
	Strings *str = StringNew();
	StringTrim(str , "MAXIS");
	RemovedWord = StringRemoveWordContaining(str , "AI");
	
	printf("RemovedWord->strings = %c\n" , RemovedWord->strings[RemovedWord->startindex]);
	printf("str->strings = %c\n" , str->strings[str->startindex]);
	/*Removed String*/
	TEST_ASSERT_EQUAL(1 , RemovedWord->startindex);
	TEST_ASSERT_EQUAL(1 , RemovedWord->length);
	/*Original String after Removed Word Containing*/
	TEST_ASSERT_EQUAL(2 , str->startindex);
	TEST_ASSERT_EQUAL(3 , str->length);
}