#pragma once

#include <stdexcept>

template<typename T>
Array_Base<T>::Array_Base()
{
	data_ = (T*)malloc(0);
	size_ = 0;
	max_size_ = 0;
}

template<typename T>
Array_Base<T>::Array_Base(size_t length)
{
	this->max_size_ = length;
  this->size_ = length;

	data_ = (T*)malloc(sizeof(T)*length);
  for (size_t i=0; i<length; i++)
  {
    this->data_[i] = T();
  }
};

template<typename T>
Array_Base<T>::Array_Base(size_t length, T fill)
{
	this->max_size_ = length;
  this->size_ = length;

	data_ = (T*)malloc(sizeof(T)*length);
	this->fill(fill);
}

template<typename T>
Array_Base<T>::Array_Base(const Array_Base <T> &arr) {
	this->max_size_ = arr.size();
  this->size_ = arr.size();

	data_ = (T*)malloc(sizeof(T)*arr.size());
	for (size_t i = 0; i < arr.size(); ++i) {
		data_[i] = arr[i];
	}
}

template<typename T>
Array_Base<T>::~Array_Base() {
	free(data_);
}

template<typename T>
const Array_Base <T> &Array_Base<T>::operator=(const Array_Base <T> &rhs) {
	if (this != &rhs) {
		free(data_);
		size_ = rhs.size();
		max_size_ = rhs.size();
		data_ = (T*)malloc(sizeof(T)*size());
		for (size_t i = 0; i < this->size_; i++)
			data_[i] = rhs.data_[i];
	}

	return *this;
}

template<typename T>
T &Array_Base<T>::operator[](size_t index) {
	if (index >= this->size_ || index < 0)
	{
		throw std::out_of_range("Array index out of bound, exiting");
  }

	return this->data_[index];
}

template<typename T>
const T &Array_Base<T>::operator[](size_t index) const {
	if (index >= this->size_ || index < 0)
	{
		throw std::out_of_range("Array index out of bound, exiting");
  }
	return this->data_[index];
}

template<typename T>
bool Array_Base<T>::operator==(const Array_Base <T> &rhs) const {
	if (this == &rhs)
	{
		return true;
	}
	if (size_ != rhs.size())
	{
		return false;
	}
	for (size_t i=0; i<size_; i++)
	{
		if (data_[i] != rhs[i])
		{
				return false;
		}
	}
	return true;
}

template<typename T>
bool Array_Base<T>::operator!=(const Array_Base <T> &rhs) const {
	return !(*(this) == rhs);
}

template<typename T>
T Array_Base<T>::get(size_t index) const {
	if (index >= this->size_ || index < 0)
	{
		throw std::out_of_range("Array index out of bound, exiting");
  }
	return data_[index];
}

template<typename T>
void Array_Base<T>::set(size_t index, T value) {
	if (index >= this->size_ || index < 0)
	{
			throw std::out_of_range("Array index out of bound, exiting");
	}
	data_[index] = value;
}

template<typename T>
int Array_Base<T>::find(T element) const
{
	for(size_t i=0; i<size_; i++)
	{
		if (data_[i] == element)
		{
			return (int)i;
		}
	}
	return -1;
}

template<typename T>
int Array_Base<T>::find(T element, size_t start) const
{
	if (start >= size() || start < 0) {
		throw std::out_of_range("Index out of bounds.");
	}
	for (size_t i = start; i < size_; i++)
	{
		if (element == data_[i])
		{
			return (int)i;
		}
	}
	return -1;
}

template<typename T>
void Array_Base<T>::fill(T element)
{
	for (size_t i = 0; i < this->size_; ++i)
	{
		data_[i] = element;
	}
}
