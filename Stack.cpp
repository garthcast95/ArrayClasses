//#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
	: max_size(20)
	, stack_arr(20)
	, stack_top(-1)
{
    // COMMENT The elements_ variable is used, but never defined.
//    this->elements = NULL;
//    this->max_size = 0;
//    this->stack_top = -1;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	: max_size(stack.max_size)
	, stack_top(stack.stack_top)
	, stack_arr(stack.max_size)
{
    // COMMENT The elements_ variable is used, but never defined.
//    this->elements = stack.elements;
//    this->stack_top = stack.stack_top;
//    this->size = stack.size;
	stack_arr = stack.stack_arr;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
   // COMMENT The elements_ variable is used, but never defined.
//    this->elements[this->stack_top] = element;
//    this->stack_top++;
//    this->size_stack++;
	if (stack_top == max_size - 1) {
		if (max_size == 0) {
			stack_arr.resize(20);
		} else {
			stack_arr.resize( 2 * max_size );
			max_size = 2 * max_size;
		}
	}
	stack_arr[++stack_top] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (!is_empty()) {
		this->stack_top--;
	} else {
		empty_exception("Stack empty can not pop!!");
	}
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs) {
		stack_arr = rhs.stack_arr;
		stack_top = rhs.stack_top;
		max_size = rhs.max_size;
	}
//	this->elements = rhs.elements ;
//	this->size_stack = rhs.size_stack ;
//    this->stack_top = rhs.stack_top;
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    this->stack_top = -1;
    this->max_size = 0;
	this->stack_arr.resize(0);
}
