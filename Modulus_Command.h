#ifndef MODULUS_COMMAND_H
#define MODULUS_COMMAND_H

#include "Binary_Expr_Command.h"

class Modulus_Command : public Binary_Expr_Command { 
public:
	Modulus_Command();

	int eval();

	int precedence();

	void printName();

	void accept(Expr_Command_Visitor * visitor);
};

#endif
