// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->stack_top + 1;
}
//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
//	return elements[this->stack_top];
	if (is_empty() == true) {
		empty_exception("Stack is empty");
	}
	return stack_arr[stack_top];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
//	if(this->stack_top == -1)
//	{
//		empty_exception e;
//	}

	return (stack_top == -1);
}
