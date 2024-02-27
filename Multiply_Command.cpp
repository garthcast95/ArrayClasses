#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack<int> &s)
	: Binary_Op_Command(s, 2)
{
}

int Multiply_Command::evaluate(int n1, int n2) const {
	return n1 * n2;
}
