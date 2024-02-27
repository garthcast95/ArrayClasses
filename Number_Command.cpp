#include "Number_Command.h"
#include "Expr_Command_Visitor.h"

Number_Command::Number_Command (int val)
: val_ (val)
{ }

//Number_Command::~Number_Command() {}

int Number_Command::eval () {
	return this->val_;
}

int Number_Command::precedence() {
	return -1;
}

void Number_Command::printName() {
	std::cout<<"Number: "<<val_<<std::endl;
}

int Number_Command::getVal() {
	return val_;
}

void Number_Command::accept(Expr_Command_Visitor * visitor) {
	visitor->visit_number (this);
}
