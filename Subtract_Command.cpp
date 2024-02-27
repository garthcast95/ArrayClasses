#include "Subtract_Command.h"
#include "Expr_Command_Visitor.h"

Subtract_Command::Subtract_Command ()
{ }

int Subtract_Command::eval () {
	return this->left_->eval()-this->right_->eval();
}

int Subtract_Command::precedence() {
	return 0;
}

void Subtract_Command::printName() {
	std::cout<<"Subtract Command"<<std::endl;
	std::cout<<"Left: ";
	this->left_->printName();
	std::cout<<"Right: ";
	this->right_->printName();
}

void Subtract_Command::accept(Expr_Command_Visitor * visitor) {
	visitor->visit_subtract_operator(this);
}
