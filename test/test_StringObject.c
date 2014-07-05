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
	Strings *str = StringNew(50);
	StringTrim(str , " 2+2");
	
	TEST_ASSERT_EQUAL(3 , strlen(str->strings));
}

/*#2*/ void test_StringTrim_should_skip_spaces_in_right_sides_and_store_in_strStrings(void)
{
	Strings *str = StringNew(50);
	StringTrim(str , "4+8+1  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#3*/ void test_StringTrim_should_skip_all_spaces_and_store_in_strStrings(void)
{
	Strings *str = StringNew(50);
	StringTrim(str , " 4 - 2 +   3  ");
	
	TEST_ASSERT_EQUAL(5 , strlen(str->strings));
}

/*#4*/ void test_StringRemoveWordContaining_given_3_plus_3_should_remove_two_3(void)
{
	Strings *RemovedWord;
	Strings *str = StringNew(50);
	StringTrim(str , " 3 + 4");
	StringRemoveWordContaining(str , "1234");
}

/*#5*/ /*void test_StringRemoveWordContaining_given_4_plus_6_minus_7_should_remove_plus_and_minus(void)
{
	Strings *str = StringNew(50);
	StringTrim(str , " 4 + 6 -7");
	StringRemoveWordContaining(str , "+-");
}*/