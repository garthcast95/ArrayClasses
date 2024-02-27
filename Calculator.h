#ifndef CALCULATOR_H_EXISTS
#define CALCULATOR_H_EXISTS

#include "Binary_Expr_Command.h"
//#include "Add_Command.h"
//#include "Subtract_Command.h"
#include "Stack.h"

class Calculator {
public:
	Calculator ();
	~Calculator ();
	void addOp (Binary_Expr_Command * op);
	void addCommand (Expr_Command * node);
	void print();
	Expr_Command * get_expression();
private:
	Stack<Expr_Command *> nodes_;
	Stack<Binary_Expr_Command *> ops_;
};

#endif
