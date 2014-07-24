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











void test_numberNew_given_value_12_should_store_inside_numberNew(void)

{

 Number *number = numberNew(12);



 if ((((number)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)23);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

}
