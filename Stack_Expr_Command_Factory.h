#ifndef STACK_EXPR_COMMAND_FACTORY_H
#define STACK_EXPR_COMMAND_FACTORY_H

#include "Stack.h"
#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory {
public:
	Stack_Expr_Command_Factory(Stack<int>& stack);
	~Stack_Expr_Command_Factory() {}

	Num_Command* create_num_command(int num) override;
	Add_Command* create_add_command() override;
	Subtract_Command* create_subtract_command() override;
	Multiply_Command* create_multiply_command() override;
	Divide_Command* create_divide_command() override;

private:
	Stack<int> &stack_; // Stack to store the operator and operand. Will be used to all commands
};


#endif //STACK_EXPR_COMMAND_FACTORY_H
