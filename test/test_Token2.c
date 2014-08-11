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
 * Given "2" 2 is a numToken , num->line should contain the location of numToken
 */
void test_getToken_given_2_should_get_2_and_pass_to_number_token(void)
{
	String *str = stringNew("2");
	Number *num = (Number*)getToken(str);

	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(2 , num->value);
	TEST_ASSERT_EQUAL(0 , num->line->startindex);
	TEST_ASSERT_EQUAL(1 , num->line->length);
	
	numberDel(num);
	stringDel(str);
}

/* 
 * Given " 50-4" 50 is a numToken , num->line should contain the location of numToken
 */
void test_getToken_given_50_minus_4_num_line_should_contain_the_numToken_location(void)
{
	String *str = stringNew(" 50-4");
	Number *num = (Number*)getToken(str);

	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(50 , num->value);
	TEST_ASSERT_EQUAL(1 , num->line->startindex);
	TEST_ASSERT_EQUAL(2 , num->line->length);
	
	numberDel(num);
	stringDel(str);
}

/* 
 * Given "_ABC" _ABC is a idenToken , iden->line should contain the location of idenToken
 */
void test_getToken_given__ABC_iden_line_should_contain_the_idenToken_location(void)
{
	String *str = stringNew("_ABC");
	Identifier *iden = (Identifier*)getToken(str);

	TEST_ASSERT_NOT_NULL(iden);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN , iden->type);
	TEST_ASSERT_EQUAL_STRING("_ABC" , iden->name);
	TEST_ASSERT_EQUAL(0 , iden->line->startindex);
	TEST_ASSERT_EQUAL(4 , iden->line->length);
	
	identifierDel(iden);
	stringDel(str);
}

/* 
 * Given "+-" + is a OperatorToken , op->line should contain the location of OperatorToken
 */
void test_getToken_given_plus_minus_op_line_should_contain_the_OperatorToken_location(void)
{
	String *str = stringNew("+-");
	Operator *op;
	op = (Operator*)getToken(str);

	TEST_ASSERT_NOT_NULL(op);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , op->type);
	TEST_ASSERT_EQUAL_STRING("+" , op->info->name);
	TEST_ASSERT_EQUAL(ADD_OP , op->info->id);
	TEST_ASSERT_EQUAL(70 , op->info->precedence);
	TEST_ASSERT_EQUAL(0 , op->line->startindex);
	TEST_ASSERT_EQUAL(1 , op->line->length);
	
	operatorDel(op);
	stringDel(str);
}

/* 
 * Given "---4" - is a OperatorToken and call getToken 3times, op->line should contain the location of OperatorToken
 */
void test_getToken_given_minusx3_4_op_line_should_contain_the_OperatorToken_location(void)
{
	String *str = stringNew("---4");
	Operator *op;
	op = (Operator*)getToken(str);

	TEST_ASSERT_NOT_NULL(op);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , op->type);
	TEST_ASSERT_EQUAL_STRING("-" , op->info->name);
	TEST_ASSERT_EQUAL(SUB_OP , op->info->id);
	TEST_ASSERT_EQUAL(70 , op->info->precedence);
	TEST_ASSERT_EQUAL(0 , op->line->startindex);
	TEST_ASSERT_EQUAL(1 , op->line->length);
	
	op = (Operator*)getToken(str);
	TEST_ASSERT_NOT_NULL(op);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , op->type);
	TEST_ASSERT_EQUAL_STRING("-" , op->info->name);
	TEST_ASSERT_EQUAL(SUB_OP , op->info->id);
	TEST_ASSERT_EQUAL(70 , op->info->precedence);
	TEST_ASSERT_EQUAL(1 , op->line->startindex);
	TEST_ASSERT_EQUAL(1 , op->line->length);
	
	op = (Operator*)getToken(str);
	TEST_ASSERT_NOT_NULL(op);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , op->type);
	TEST_ASSERT_EQUAL_STRING("-" , op->info->name);
	TEST_ASSERT_EQUAL(SUB_OP , op->info->id);
	TEST_ASSERT_EQUAL(70 , op->info->precedence);
	TEST_ASSERT_EQUAL(2 , op->line->startindex);
	TEST_ASSERT_EQUAL(1 , op->line->length);
	
	operatorDel(op);
	stringDel(str);
}

/* 
 * Given "4 && 8" and getToken 2times
 * should get numToken 4 and operatorToken &&
 */
void test_getToken_given_4_logical_AND_8_and_getToken_2times_should_get_NumberToken_and_OperatorToken(void)
{
	String *str = stringNew("4 && 8");
	Number *num;
	Operator *op;
	
	num = (Number*)getToken(str);
	
	TEST_ASSERT_NOT_NULL(num);
	TEST_ASSERT_EQUAL(NUMBER_TOKEN , num->type);
	TEST_ASSERT_EQUAL(4 , num->value);
	TEST_ASSERT_EQUAL(0 , num->line->startindex);
	TEST_ASSERT_EQUAL(1 , num->line->length);
	
	op = (Operator*)getToken(str);

	TEST_ASSERT_NOT_NULL(op);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN , op->type);
	TEST_ASSERT_EQUAL_STRING("&&" , op->info->name);
	TEST_ASSERT_EQUAL(AND_OP , op->info->id);
	TEST_ASSERT_EQUAL(30 , op->info->precedence);
	TEST_ASSERT_EQUAL(2 , op->line->startindex);
	TEST_ASSERT_EQUAL(2 , op->line->length);
	
	operatorDel(op);
	stringDel(str);
}