#include "NumberToken.h"
#include "Token.h"
#include <malloc.h>

/* Create new structure for number token
 * input :
 *			value is the number need to be store in this structure
 * return :
 *			return the num pointer which is numberToken
 */
Number *numberNew(int value)
{
	Number *num = malloc(sizeof(Number));
	num->type	= NUMBER_TOKEN;
	num->value	= value;
	
	return num;
}