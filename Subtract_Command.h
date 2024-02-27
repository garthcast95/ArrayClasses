#ifndef SUBTRACT_COMMAND_H
#define SUBTRACT_COMMAND_H

#include "Binary_Expr_Command.h"

class Subtract_Command : public Binary_Expr_Command {
public:
	Subtract_Command ();

	int eval ();

	int precedence();

	void printName();

	void accept(Expr_Command_Visitor * visitor);
};

#endif
