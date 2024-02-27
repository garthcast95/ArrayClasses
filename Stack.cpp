// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#include "Stack.h"

template <typename T>
Stack <T>::Stack (void)
: arr (Array<T>()),
head (-1)
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: arr (Array<T>(stack.arr)),
head (stack.head)
{

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
	// if there is still room in the current array to expand
	if (head + 1 < (int)arr.size()){
		head++;
		arr.set(head, element);
	// if we can expand the array without allocating new memory
	}else if (arr.size() < arr.max_size()) {
		arr.resize(arr.size()+1);
		head++;
		arr.set(head, element);
	} else{
		arr.resize(arr.size()*2+1);
		head++;
		arr.set(head, element);
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if(head != -1){
		head--;
	}else {
		throw empty_exception();
	}
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	head = rhs.head;
	arr = rhs.arr;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	head = -1;
}

template <typename T>
void Stack <T>::reverse() {
	arr.resize(head+1);
	arr.reverse();
}
