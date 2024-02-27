#ifndef DIVIDE_COMMAND_H_EXISTS
#define DIVIDE_COMMAND_H_EXISTS

#include "Binary_Expr_Command.h"

class Divide_Command : public Binary_Expr_Command { 
public:
	Divide_Command ();

	int eval ();

	int precedence();

	void printName();

	void accept(Expr_Command_Visitor * visitor);
};


#endif
