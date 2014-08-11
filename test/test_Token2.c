#include "unity.h"
#include "Token.h"
#include "StringObject.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "IdentifierToken.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/* 
 * Given "  2  " make this integer 2 become number token
 */
void test_getToken_given_2_should_get_2_and_pass_to_number_token(void)
{
	String *str = stringNew("2");
	Number *num;
	num = (Number*)getToken(str);

	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(2 , num->value);
	
	numberDel(num);
	stringDel(str);
}
