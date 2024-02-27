// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//#include "Array.h"
#pragma once

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template<typename T>
Array<T>::Array(void)
		: Array_Base<T>() {
}

//
// Array (size_t)
//
template<typename T>
Array<T>::Array(size_t length)
		: Array_Base<T>(length) {
}

//
// Array (size_t, char)
//
template<typename T>
Array<T>::Array(size_t length, T fill)
		: Array_Base<T>(length, fill) {
}

//
// Array (const Array &)
//
template<typename T>
Array<T>::Array(const Array <T> &array)
		: Array_Base<T>(array) {
}

//
// ~Array
//
template<typename T>
Array<T>::~Array(void)
{
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array<T> & rhs)
{
  if (this != &rhs) {
		this->size_ = rhs.size();
		this->max_size_ = rhs.size();
		this->data_ = (T*)malloc(sizeof(T)*this->size());
		for (size_t i = 0; i < this->size_; i++)
			this->data_[i] = rhs.data_[i];
	}

	return *this;
}

//
// resize
//
template<typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size == this->size())
	{
		return;
	}

	T * copy;
	if (new_size > this->max_size_)
	{
		copy = (T*)malloc(sizeof(T)*new_size);
		for (size_t i=0; i<this->size(); i++)
		{
			copy[i] = this->data_[i];
		}
		for (size_t i=this->size(); i<new_size; i++)
		{
			copy[i] = T();
		}
		free(this->data_);
		this->data_ = copy;
		this->max_size_ = new_size;
	}

	this->size_ = new_size;
}
