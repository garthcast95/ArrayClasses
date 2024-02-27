#ifndef SUBTRACT_COMMAND_H
#define SUBTRACT_COMMAND_H

#include "Stack.h"
#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command {
public:
	Subtract_Command(Stack<int>& s);
	int evaluate(int n1, int n2) const override;
};


#endif //SUBTRACT_COMMAND_H
