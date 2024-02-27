#ifndef Expr_Command_H_EXISTS
#define Expr_Command_H_EXISTS

#include <iostream>
class Expr_Command_Visitor;

class Expr_Command {
public:
	Expr_Command ();
	virtual ~Expr_Command();
	virtual int eval() = 0;
	virtual int precedence() = 0;
	virtual void printName() = 0;
	virtual void accept(Expr_Command_Visitor * visitor) = 0;
};

#endif
