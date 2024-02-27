#ifndef MULTIPLY_COMMAND_H
#define MULTIPLY_COMMAND_H

#include "Stack.h"
#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command {
public:
	Multiply_Command(Stack<int>& s);
	int evaluate(int n1, int n2) const override;
};

#endif //MULTIPLY_COMMAND_H
