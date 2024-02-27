#include "Divide_Command.h"
#include "Expr_Command_Visitor.h"

Divide_Command::Divide_Command ()
{ }

int Divide_Command::eval () {
	return this->left_->eval() / this->right_->eval();
}

int Divide_Command::precedence() {
	return 1;
}

void Divide_Command::printName() {
	std::cout<<"Divide Command"<<std::endl;
}

void Divide_Command::accept(Expr_Command_Visitor * visitor) {
	visitor->visit_divide_operator(this);
}
