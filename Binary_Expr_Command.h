#ifndef BINARY_EXPR_COMMAND_H_EXISTS
#define BINARY_EXPR_COMMAND_H_EXISTS

#include "Expr_Command.h"

class Binary_Expr_Command : public Expr_Command {
public:
	Binary_Expr_Command ();
	Binary_Expr_Command (Expr_Command * left, Expr_Command * right);
	~Binary_Expr_Command();
	virtual int eval () = 0;
	void setLeft (Expr_Command * left);
	void setRight (Expr_Command * right);
	Expr_Command * getRight();
	Expr_Command * getLeft();
	virtual int precedence() = 0;
	virtual void printName() = 0;
protected:
	Expr_Command * left_;
	Expr_Command * right_;
};
#endif
