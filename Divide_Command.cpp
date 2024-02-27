#include <stdexcept>
#include "Divide_Command.h"

Divide_Command::Divide_Command(Stack<int> &s)
	: Binary_Op_Command(s, 2)
{
}

int Divide_Command::evaluate(int n1, int n2) const {
	if (n2 == 0)
		throw std::runtime_error("Division by error");

	return (n1 / n2);
}
