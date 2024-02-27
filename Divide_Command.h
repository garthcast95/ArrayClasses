#ifndef DIVIDE_COMMAND_H
#define DIVIDE_COMMAND_H

#include "Stack.h"
#include "Binary_Op_Command.h"

class Divide_Command : public Binary_Op_Command {
public:
	Divide_Command(Stack<int> &s);
	int evaluate(int n1, int n2) const override;
};


#endif //DIVIDE_COMMAND_H
