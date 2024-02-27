#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder ()
: expressions (Stack<Calculator *>())
{
	expressions.push(new Calculator());
}

Expr_Tree_Builder::~Expr_Tree_Builder () {
	while (!expressions.is_empty()) {
		delete expressions.top();
		expressions.pop();
	}
}

void Expr_Tree_Builder::build_number (int num) {
	expressions.top()->addCommand(new Number_Command(num));
}

void Expr_Tree_Builder::build_add_operator () {
	expressions.top()->addOp(new Add_Command());
}

void Expr_Tree_Builder::build_subtract_operator () {
	expressions.top()->addOp(new Subtract_Command());
}

void Expr_Tree_Builder::build_multiply_operator () {
	expressions.top()->addOp(new Multiply_Command());
}

void Expr_Tree_Builder::build_divide_operator () {
	expressions.top()->addOp(new Divide_Command());
}

void Expr_Tree_Builder::build_modulus_operator () {
	expressions.top()->addOp(new Modulus_Command());
}

void Expr_Tree_Builder::build_open_parenthesis () {
	expressions.push(new Calculator());
}

void Expr_Tree_Builder::build_close_parenthesis () {
	Expr_Command * head = expressions.top()->get_expression();
	expressions.pop();
	expressions.top()->addCommand(head);
}

Expr_Command * Expr_Tree_Builder::get_expression () {
	return expressions.top()->get_expression();
}
