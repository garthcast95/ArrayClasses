#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Array.h"
#include "Stack_Expr_Command_Factory.h"
#include <string>

class Calculator {
public:
	bool infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix);
};


#endif //CALCULATOR_H
