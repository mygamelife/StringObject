#include "NumberToken.h"

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

/* Delete number token
 * input :
 *			number pointer pointing number token structure
 * output :
 *			clear number token value and free the memory allocated
 */
void numberDel(Number *num)
{
	if(num)
		free(num);
}