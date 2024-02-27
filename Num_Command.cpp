#include "Num_Command.h"

Num_Command::Num_Command(Stack<int> &s, int n)
	: s_(s)
	, n_(n)
{
}

bool Num_Command::execute() {
	s_.push(this->n_);
	return true;
}
