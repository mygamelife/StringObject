#include "unity.h"
#include "OperatorToken.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*#1
 * Test create new operator token identify by the operator ID, given plus operator ID ADD_OP
 * operator->info shouldn't be NULL and operator->info should contain operator information
 */
void test_operatorNewByID_given_operator_ID_ADD_OP_should_store_operator_info_inside_operatorNewByID(void)
{
	Operator *operator;
	operator = operatorNewByID(ADD_OP);
	
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , operator->type);
	TEST_ASSERT_NOT_NULL(operator->info);
	TEST_ASSERT_EQUAL(ADD_OP , operator->info->id);
	operatorDel(operator);
}

/*#2
 * Test create new operator token identify by the operator ID, given plus operator ID 15
 * operator->info should be NULL and don't contain any information about operator
 */
void test_operatorNewByID_given_operator_ID_15_should_store_nothing_information_inside_operatorNewByID(void)
{
	Operator *operator;
	operator = operatorNewByID(20);
	
	TEST_ASSERT_NULL(operator);
	operatorDel(operator);
}

/*#3
 * Test create new operator token identify by the operator name, given operator name "*"
 * operator->info shouldn't be NULL and operator->info should contain operator information
 */
void test_operatorNewByName_given_multiply_operator_name_should_store_multiply_operator_info(void)
{
	Operator *operator;
	operator = operatorNewByName("*");
	
	TEST_ASSERT_NOT_NULL(operator->info);
	TEST_ASSERT_EQUAL_STRING("*" , operator->info->name);
	TEST_ASSERT_EQUAL(MUL_OP , operator->info->id);
	TEST_ASSERT_EQUAL(80 , operator->info->precedence);
	operatorDel(operator);
}

/*#3
 * Test create new operator token identify by the operator name, given operator name "-"
 * operator->info shouldn't be NULL and operator->info should contain operator information
 */
void test_operatorNewByName_given_minus_operator_name_should_store_minus_operator_info(void)
{
	Operator *operator;
	operator = operatorNewByName("-");
	
	TEST_ASSERT_NOT_NULL(operator->info);
	TEST_ASSERT_EQUAL_STRING("-" , operator->info->name);
	TEST_ASSERT_EQUAL(SUB_OP , operator->info->id);
	TEST_ASSERT_EQUAL(70 , operator->info->precedence);
	operatorDel(operator);
}
/*#4
 * Test create new operator token identify by the operator name, given operator name "]"
 * operator->info should be NULL and operator->info contain nothing
 */
void test_operatorNewByName_given_square_bracket_name_should_store_nothing(void)
{
	Operator *operator;
	operator = operatorNewByName("[");
	
	TEST_ASSERT_NULL(operator);
	operatorDel(operator);
}