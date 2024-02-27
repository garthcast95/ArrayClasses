#include "Subtract_Command.h"

Subtract_Command::Subtract_Command(Stack<int> &s)
	: Binary_Op_Command(s, 1)
{
}

int Subtract_Command::evaluate(int n1, int n2) const {
	return n1 - n2;
}
