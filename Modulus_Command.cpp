#include "Modulus_Command.h"
#include "Expr_Command_Visitor.h"

Modulus_Command::Modulus_Command ()
{ }

int Modulus_Command::eval() {
	return this->left_->eval() % this->right_->eval();
}

int Modulus_Command::precedence() {
	return 1;
}

void Modulus_Command::printName() {
	std::cout<<"Modulus Command"<<std::endl;
	std::cout<<"Left: ";
	this->left_->printName();
	std::cout<<"Right: ";
	this->right_->printName();
}

void Modulus_Command::accept(Expr_Command_Visitor * visitor) {
	visitor->visit_modulus_operator(this);
}
