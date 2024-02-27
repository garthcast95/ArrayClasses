#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include "Stack.h"
#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command {
public:
	Add_Command(Stack<int> &s);
	int evaluate(int n1, int n2) const override;
};

#endif //ADD_COMMAND_H
