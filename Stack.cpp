#pragma once

//#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
{
    // COMMENT The elements_ variable is used, but never defined.
//    this->elements = NULL;
//    this->max_size = 0;
//    this->stack_top = -1;
	stack_arr.resize(5);
	stack_top = -1;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
    // COMMENT The elements_ variable is used, but never defined.
//    this->elements = stack.elements;
//    this->stack_top = stack.stack_top;
//    this->size = stack.size;
	stack_arr = stack.stack_arr;
	stack_top = stack.stack_top;
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
	stack_top++;
  int os = stack_arr.size();
  if (stack_top >= os)
  {
    stack_arr.resize(os*2);
  }
  stack_arr.set(stack_top, element);
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
		throw(empty_exception());
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
    stack_top = -1;
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
  return stack_top == -1;
}

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
  return stack_top+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
  return (stack_top == -1) ? throw(empty_exception()) : stack_arr.get(stack_top);
}
