#include "unity.h"
#include "OperatorToken.h"
#include "CException.h"
#include "ErrorCode.h"
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
 * Given UNKNOWN OPERATOR ID and should throw an exception error
 */
void test_operatorNewByID_given_operator_ID_UNKNOWN_OP_should_Throw_Exception(void)
{
	CEXCEPTION_T err;
	Operator *operator = NULL;
	
	Try
	{
		operator = operatorNewByID(UNKNOWN_OP);
		TEST_FAIL_MESSAGE("Should throw ERR_UNKNOWN_OPERATOR exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_UNKNOWN_OPERATOR , err , "Expect ERR_UNKNOWN_OPERATOR exception");
		TEST_ASSERT_NULL(operator);
	}
	
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
 * Given "[" operator should throw an exception 
 * because this operator not contain in primary operator table
 */
void test_operatorNewByName_given_square_bracket_name_should_store_nothing(void)
{
	CEXCEPTION_T err;
	Operator *operator;	
	
	Try
	{
		operator = operatorNewByName("[");
		TEST_FAIL_MESSAGE("Should throw ERR_UNKNOWN_OPERATOR exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_UNKNOWN_OPERATOR , err , "Expect ERR_UNKNOWN_OPERATOR exception");
	}
	
	operatorDel(operator);
}

void test_operatorNewByName_given_curly_bracket_name_should_store_nothing(void)
{
	CEXCEPTION_T err;
	Operator *operator;	
	
	Try
	{
		operator = operatorNewByName("{}");
		TEST_FAIL_MESSAGE("Should throw ERR_UNKNOWN_OPERATOR exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_UNKNOWN_OPERATOR , err , "Expect ERR_UNKNOWN_OPERATOR exception");
	}
	
	operatorDel(operator);
}
