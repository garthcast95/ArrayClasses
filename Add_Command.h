#ifndef ADD_COMMAND_H_EXISTS
#define ADD_COMMAND_H_EXISTS

#include "Binary_Expr_Command.h"

class Add_Command : public Binary_Expr_Command {
public:
	Add_Command ();
	int eval ();
	int precedence();
	void printName();
	void accept(Expr_Command_Visitor * visitor);
};
#endif
