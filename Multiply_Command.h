#ifndef MULTIPLY_COMMAND_H
#define MULTIPLY_COMMAND_H

#include "Binary_Expr_Command.h"

class Multiply_Command : public Binary_Expr_Command {
public:
	Multiply_Command ();

	int eval ();

	int precedence();

	void printName();

	void accept(Expr_Command_Visitor * visitor);
};

#endif
