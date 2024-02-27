#include "Multiply_Command.h"
#include "Expr_Command_Visitor.h"

Multiply_Command::Multiply_Command ()
{ }

int Multiply_Command::eval() {
	return this->left_->eval () * this->right_->eval ();
}

int Multiply_Command::precedence() {
	return 1;
}

void Multiply_Command::printName() {
	std::cout<<"Multiply Command"<<std::endl;
	std::cout<<"Left: "<<std::endl;
	left_->printName();
	std::cout<<"Right: "<<std::endl;
	right_->printName();
}

void Multiply_Command::accept(Expr_Command_Visitor * visitor) {
	visitor->visit_multiply_operator(this);
}
