#include "unity.h"
#include "Token.h"
#include "StringObject.h"


void setUp(void)

{

}



void tearDown(void)

{

}







void test_getToken_given_2_should_get_2_and_pass_to_number_token(void)

{

 String *str = stringNew("  2  ");

 getToken(str);

}
