#include "unity.h"
#include "NumberToken.h"
#include "Token.h"
#include "StringObject.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*#1
 * Test create new number token given value 12
 * inside number token structure should included NUMBER_TOKEN type and value 12 
 */
void test_numberNew_given_value_12_should_store_inside_numberNew(void)
{
	Number *number = numberNew(12);
	
	TEST_ASSERT_NOT_NULL(number);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , number->type);
	TEST_ASSERT_EQUAL(12 , number->value);
}