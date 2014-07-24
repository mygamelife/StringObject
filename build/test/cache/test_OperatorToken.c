#include "unity.h"
#include "OperatorToken.h"


void setUp(void)

{

}



void tearDown(void)

{

}











void test_operatorNewByID_given_operator_ID_ADD_OP_should_store_operator_info_inside_operatorNewByID(void)

{

 Operator *operator;

 operator = operatorNewByID(ADD_OP);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 if ((((operator->info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)22);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

 operatorDel(operator);

}











void test_operatorNewByID_given_operator_ID_15_should_store_nothing_information_inside_operatorNewByID(void)

{

 Operator *operator;

 operator = operatorNewByID(15);



 if ((((operator)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 operatorDel(operator);

}











void test_operatorNewByName_given_multiply_operator_name_should_store_multiply_operator_info(void)

{

 Operator *operator;

 operator = operatorNewByName("*");



 if ((((operator->info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)49);;};

 UnityAssertEqualString((const char*)("*"), (const char*)(operator->info->name), (((void *)0)), (_U_UINT)50);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

 operatorDel(operator);

}











void test_operatorNewByName_given_square_bracket_name_should_store_nothing(void)

{

 Operator *operator;

 operator = operatorNewByName("[");



 if ((((operator)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)65);;};

 operatorDel(operator);

}
