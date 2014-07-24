#include "unity.h"
#include "Token.h"
#include "StringObject.h"
#include "OperatorToken.h"
#include "NumberToken.h"


void setUp(void)

{

}



void tearDown(void)

{

}









void test_getToken_given_2_should_get_2_and_pass_to_number_token(void)

{

 String *str = stringNew("  2  ");

 Number *num = (Number*)getToken(str);



 if ((((num)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)23);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((num->type)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((num->value)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

}









void test_getToken_given_tab_841_should_get_841_and_pass_to_number_token(void)

{

 String *str = stringNew("\t 841  ");

 Number *num = (Number*)getToken(str);



 if ((((num)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)36);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((num->type)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((841)), (_U_SINT)((num->value)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

}









void test_getToken_given_tab_23_40_tab_and_getToken_x2_should_get_number_token_value_40(void)

{

 String *str = stringNew("\t 23 40 \t");

 (Number*)getToken(str);

 (Number*)getToken(str);









}









void test_getToken_given_AND_operator_in_string_should_get_AND_operator_and_return_as_an_operator_token(void)

{

 String *str = stringNew(" && ");

 Token *token = getToken(str);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}









void test_getToken_given_multiply_operator_in_string_should_get_multiply_operator_and_return_as_an_operator_token(void)

{

 String *str = stringNew(" * ");

 Token *token = getToken(str);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

}









void test_getToken_given_open_square_bracket_should_return_NULL(void)

{

 String *str = stringNew(" [ ");

 Token *token = getToken(str);

 if ((((token)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)84);;};

}
