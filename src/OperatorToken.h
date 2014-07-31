#ifndef OperatorToken_H
#define OperatorToken_H
#include "Token.h"

typedef enum
{
	NO_ASSOCIATIVITY,
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT
}AssocType;

typedef enum
{
	PREFIX,
	INFIX,
	POSTFIX
}Affix;

typedef enum
{
	UNKNOWN_OP, //Unknown
	ADD_OP, // "+"
	SUB_OP, // "-" 
	MUL_OP, // "*"
	NPERCENT_OP, // "%"
	DIV_OP, // "/"
	OR_OP, // "||"
	AND_OP, // "&&"
	XOR_OP, // "^"
	BITWISE_OR_OP, // "|"
	BITWISE_AND_OP, // "&"
	NOT_OP, // "!"
	BITWISE_NOT_OP, // "~"
	BITWISE_SHIFT_LEFT_OP, // "<<"
	BITWISE_SHIFT_RIGHT_OP, // ">>"
	LESSER_OP, // "<"
	GREATER_OP, // ">"
	EQUAL_OP, // "=="
	OPEN_BRACKET, // "("
	CLOSE_BRACKET // ")"
}OperatorID;

typedef struct
{
	char *name;
	OperatorID id;
	int precedence;
	AssocType associativity;
	Affix affix;
}OperatorInfo;

typedef struct
{
	TokenType type;
	OperatorInfo *info;
}Operator;

Operator *operatorNewByID(OperatorID id);
Operator *operatorNewByName(char *name);
void operatorDel(Operator *op);

#endif // OperatorToken_H
