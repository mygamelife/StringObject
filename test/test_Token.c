#include "unity.h"
#include "Token.h"
#include "StringObject.h"
#include "NumberToken.h"
#include "OperatorToken.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/* #1
 * Given "  2  " make this integer 2 become number token
 */
void test_getToken_given_2_should_get_2_and_pass_to_number_token(void)
{
	String *str = stringNew("  2  ");
	Number *num = (Number*)getToken(str);

	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(2 , num->value);
}

/* #2
 * Given "\t 841  " make this integer 841 become number token
 */
void test_getToken_given_tab_841_should_get_841_and_pass_to_number_token(void)
{
	String *str = stringNew("\t 841  ");
	Number *num = (Number*)getToken(str);

	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(841 , num->value);	
}

/* #3
 * Given "\t 23 40 \t" and getToken twice now the number token value should be 40
 */
void test_getToken_given_tab_23_40_tab_and_getToken_x2_should_get_number_token_value_40(void)
{
	String *str = stringNew("\t 23 40 \t");
	(Number*)getToken(str);
	(Number*)getToken(str);

	// TEST_ASSERT_NOT_NULL(num);
	// TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);	
	// TEST_ASSERT_EQUAL(23 , num->value);	
}

/* #3
 * Given " && " should return this as an operator token 
 */
void test_getToken_given_AND_operator_in_string_should_get_AND_operator_and_return_as_an_operator_token(void)
{
	String *str = stringNew(" && ");
	Token *token = getToken(str);

	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , token->type);
}

/* #4
 * Given " * " should return this as an operator token 
 */
void test_getToken_given_multiply_operator_in_string_should_get_multiply_operator_and_return_as_an_operator_token(void)
{
	String *str = stringNew(" * ");
	Token *token = getToken(str);

	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , token->type);
}

/* #5
 * Given " [ " should return NULL because " [ " is not in the primaryOperatorTable
 */
void test_getToken_given_open_square_bracket_should_return_NULL(void)
{
	String *str = stringNew(" [ ");
	Token *token = getToken(str);
	TEST_ASSERT_NULL(token);
}