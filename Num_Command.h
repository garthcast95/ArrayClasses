#ifndef NUM_COMMAND_H
#define NUM_COMMAND_H

#include "Stack.h"
#include "Expr_Command.h"

class Num_Command : public Expr_Command {
public:
	Num_Command(Stack<int>& s, int n);

	bool execute() override;
	int getPrecedence() const override {
		return 0;
	}

private:
	Stack<int>& s_;
	int n_;
};


#endif //NUM_COMMAND_H
