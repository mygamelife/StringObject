#include "OperatorToken.h"
#include <malloc.h>
#define PRIMARY_TABLE_SIZE (sizeof(primaryOperatorTable)/sizeof(OperatorInfo))

/* Operator Table contain all the operator information
 */
OperatorInfo primaryOperatorTable[] = 
{
	{.name = "+", 	.id = ADD_OP, 			.precedence = 70, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "-", 	.id = SUB_OP, 			.precedence = 70, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "*", 	.id = MUL_OP, 			.precedence = 80, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "%", 	.id = NPERCENT_OP, 		.precedence = 80, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "/", 	.id = DIV_OP, 			.precedence = 80, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "||", 	.id = OR_OP, 			.precedence = 40, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "^", 	.id = XOR_OP, 			.precedence = 50, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "&&", 	.id = AND_OP, 			.precedence = 60, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "&", 	.id = BITWISE_AND_OP, 	.precedence = 30, .associativity = LEFT_TO_RIGHT, .affix = INFIX},
	{.name = "|", 	.id = BITWISE_OR_OP, 	.precedence = 20, .associativity = LEFT_TO_RIGHT, .affix = INFIX}	
};

/* Create new structure for operator (Identify by ID)
 * input :
 *			operator ID to indicate which operator is this
 * return :
 *			return the op pointer which is operatorToken
 */
Operator *operatorNewByID(OperatorID id)
{
	int i = 0;
	Operator *op = malloc(sizeof(Operator)); //*op = operator pointer
	op->type	 = OPERATOR_TOKEN;
	
	for(i ; i < PRIMARY_TABLE_SIZE ; i++)
	{
		if(primaryOperatorTable[i].id == id)
		{
			op->info = &primaryOperatorTable[i];
			return op;
		}
	}
	
	return NULL;
}

/* Create new structure for operator (Identify by ID)
 * input :
 *			operator ID to indicate which operator is this
 * return :
 *			return the op pointer which is operatorToken
 */
Operator *operatorNewByName(char *name)
{
	int i = 0 , result;
	Operator *op = malloc(sizeof(Operator)); //*op = operator pointer
	op->type	 = OPERATOR_TOKEN;
	
	for(i ; i < PRIMARY_TABLE_SIZE ; i++)
	{
		result = strcmp(primaryOperatorTable[i].name, name);
		
		if(result == 0)
		{
			op->info = &primaryOperatorTable[i];
			return op;
		}
	}
	
	return NULL;
}

/* Delete operator token
 * input :
 *			Operator pointer pointing operator token structure
 * output :
 *			clear operator token value and free the memory allocated
 */
void operatorDel(Operator *op)
{
	if(op)		
		free(op);
}