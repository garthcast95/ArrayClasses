#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int> &stack)
	: stack_(stack)
{
}

Num_Command *Stack_Expr_Command_Factory::create_num_command(int num) {
	return new Num_Command(stack_, num);
}

Add_Command *Stack_Expr_Command_Factory::create_add_command() {
	return new Add_Command(stack_);
}

Subtract_Command *Stack_Expr_Command_Factory::create_subtract_command() {
	return new Subtract_Command(stack_);
}

Multiply_Command *Stack_Expr_Command_Factory::create_multiply_command() {
	return new Multiply_Command(stack_);
}

Divide_Command *Stack_Expr_Command_Factory::create_divide_command() {
	return new Divide_Command(stack_);
}
