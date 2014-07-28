#include "unity.h"
#include "IdentifierToken.h"


void setUp(void)

{

}



void tearDown(void)

{

}











void test_identifierNew_given_ABC_should_store_inside_identifierNew(void)

{

 Identifier *identifier = identifierNew("ABC");



 if ((((identifier)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)20);;};

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("ABC"), (const char*)(identifier->name), (((void *)0)), (_U_UINT)22);



 identifierDel(identifier);

}
