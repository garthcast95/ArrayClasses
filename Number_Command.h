#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include "Expr_Command.h"

class Number_Command : public Expr_Command { 
public:
	Number_Command(int val);
	
	//~Number_Command();

	int eval();

	int precedence();

	void printName();
	
	int getVal();

	void accept (Expr_Command_Visitor * visitor);
private:
	int val_;
};

#endif
