#include "Binary_Op_Command.h"

Binary_Op_Command::Binary_Op_Command(Stack<int> &s, int precedence)
	: s_(s)
	, precedence_(precedence)
{
}

bool Binary_Op_Command::execute() {
	int n2 = s_.top();
	s_.pop();
	int n1 = s_.top();
	s_.pop();
	int result = this->evaluate(n1, n2);
	s_.push(result);
	return true;
}

int Binary_Op_Command::getPrecedence() const {
	return precedence_;
}
