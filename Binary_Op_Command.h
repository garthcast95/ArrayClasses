#ifndef BINARY_OP_COMMAND_H
#define BINARY_OP_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command {
protected:
	Binary_Op_Command(Stack<int>& s, int precedence_);

public:
	bool execute() override;
	virtual int evaluate(int n1, int n2) const = 0;

	int getPrecedence() const override;

private:
	Stack<int>& s_;
	int precedence_;
};

#endif // BINARY_OP_COMMAND_H
