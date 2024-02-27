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
	return head+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (head == -1) {
		throw empty_exception();
	}
	return arr.get(head);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return head == -1;
}
