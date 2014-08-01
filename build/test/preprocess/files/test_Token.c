#include "unity.h"
#include "Token.h"
#include "StringObject.h"
#include "OperatorToken.h"
#include "NumberToken.h"
#include "IdentifierToken.h"
#include "ErrorCode.h"
#include "CException.h"


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



 if ((((num)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)26);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((num->type)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((num->value)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);



 numberDel(num);

 stringDel(str);

}









void test_getToken_given_tab_841_should_get_841_and_pass_to_number_token(void)

{

 String *str = stringNew("\t 841  ");

 Number *num = (Number*)getToken(str);



 if ((((num)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)42);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((num->type)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((841)), (_U_SINT)((num->value)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);



 numberDel(num);

 stringDel(str);

}









void test_getToken_given_tab_23_40_tab_and_getToken_x2_should_get_number_token_value_40(void)

{

 String *str = stringNew("\t 23 40 \t");

 Number *num;

 num = (Number*)getToken(str);

 num = (Number*)getToken(str);



 if ((((num)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)60);;};

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((num->type)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((num->value)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);



 numberDel(num);

 stringDel(str);

}









void test_getToken_given_tab_space_tab_and_getToken_should_return_NULL(void)

{

 String *str = stringNew("\t  \t");

 Number *num = (Number*)getToken(str);



 if ((((num)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)76);;};



 numberDel(num);

 stringDel(str);

}









void test_getToken_given_AND_operator_in_string_should_get_AND_operator_and_return_as_an_operator_token(void)

{

 String *str = stringNew(" && ");

 Operator *op = (Operator*)getToken(str);



 if ((((op)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)90);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((op->type)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(op->info->name), (((void *)0)), (_U_UINT)92);

 UnityAssertEqualNumber((_U_SINT)((AND_OP)), (_U_SINT)((op->info->id)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);



 operatorDel(op);

 stringDel(str);

}









void test_getToken_given_multiply_operator_in_string_should_get_multiply_operator_and_return_as_an_operator_token(void)

{

 String *str = stringNew(" * ");

 Operator *op = (Operator*)getToken(str);



 if ((((op)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)107);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((op->type)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("*"), (const char*)(op->info->name), (((void *)0)), (_U_UINT)109);

 UnityAssertEqualNumber((_U_SINT)((MUL_OP)), (_U_SINT)((op->info->id)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);



 operatorDel(op);

 stringDel(str);

}









void test_getToken_given_addition_operator_and_percentage_operator_in_string_call_getToken_x2_should_get_percentage_operator_and_return_as_an_operator_token(void)

{

 String *str = stringNew(" + % ");

 Operator *op;

 op = (Operator*)getToken(str);

 op = (Operator*)getToken(str);



 if ((((op)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)126);;};

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((op->type)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("%"), (const char*)(op->info->name), (((void *)0)), (_U_UINT)128);

 UnityAssertEqualNumber((_U_SINT)((NPERCENT_OP)), (_U_SINT)((op->info->id)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);



 operatorDel(op);

 stringDel(str);

}









void test_getToken_given_open_square_bracket_should_return_NULL(void)

{

 String *str = stringNew(" [ ");

 Operator *op = (Operator*)getToken(str);



 if ((((op)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)143);;};



 operatorDel(op);

 stringDel(str);

}









void test_getToken_given_MAX_should_store_MAX_in_identifier_token(void)

{

 String *str = stringNew("MAX");

 Identifier *iden = (Identifier*)getToken(str);



 if ((((iden)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)157);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((iden->type)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("MAX"), (const char*)(iden->name), (((void *)0)), (_U_UINT)159);



 identifierDel(iden);

 stringDel(str);

}









void test_getToken_given__MAX_Mas2_should_store__MAX_Mas2_in_identifier_token(void)

{

 String *str = stringNew("_MAX_Mas2");

 Identifier *iden = (Identifier*)getToken(str);



 if ((((iden)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)173);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((iden->type)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("_MAX_Mas2"), (const char*)(iden->name), (((void *)0)), (_U_UINT)175);



 identifierDel(iden);

 stringDel(str);

}









void test_getToken_given_MAX232_plus_4_should_store_MAX232_in_identifier_token(void)

{

 String *str = stringNew("MAX232 + 4");

 Identifier *iden = (Identifier*)getToken(str);



 if ((((iden)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)189);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((iden->type)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("MAX232"), (const char*)(iden->name), (((void *)0)), (_U_UINT)191);



 identifierDel(iden);

 stringDel(str);

}









void test_getToken_given_124_plus_MAX80_should_store_MAX80_in_identifier_token(void)

{

 String *str = stringNew("124 MAX80");

 Identifier *iden;

 iden = (Identifier*)getToken(str);

 iden = (Identifier*)getToken(str);



 if ((((iden)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)207);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((iden->type)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("MAX80"), (const char*)(iden->name), (((void *)0)), (_U_UINT)209);



 identifierDel(iden);

 stringDel(str);

}









void test_getToken_given_456_MAX_should_return_NULL(void)

{

 unsigned int err;



 String *str;

 Identifier *iden = ((void *)0);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  str = stringNew("456_MAX");

  iden = (Identifier*)getToken(str);

  UnityFail( ("Should throw ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)229);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

  if ((((iden)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)234);;};

 }



 identifierDel(iden);

 stringDel(str);

}









void test_getToken_given_123zye_should_return_NULL(void)

{

 unsigned int err;



 String *str;

 Identifier *iden = ((void *)0);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  str = stringNew("123zye");

  iden = (Identifier*)getToken(str);

  UnityFail( ("Should throw ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)255);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

  if ((((iden)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)260);;};

 }



 identifierDel(iden);

 stringDel(str);

}
