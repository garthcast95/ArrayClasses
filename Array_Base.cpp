#include <stdexcept>
//#include "Array_Base.h"

template<typename T>
Array_Base<T>::Array_Base()
		: max_size_(20), size_(20), data_(new T[20]) {
}

template<typename T>
Array_Base<T>::Array_Base(size_t length)
		: max_size_(length), size_(length), data_(new T[length]) {
}

template<typename T>
Array_Base<T>::Array_Base(size_t length, T fill)
		: max_size_(length), size_(length), data_(new T[length]) {
	fill(fill);
}

template<typename T>
Array_Base<T>::Array_Base(const Array_Base <T> &arr)
		: max_size_(arr.max_size_), size_(arr.size_), data_(new T[arr.size_]) {
	for (int i = 0; i < arr.size_; ++i) {
		data_[i] = arr[i];
	}
}

template<typename T>
Array_Base<T>::~Array_Base() {
	delete[] data_;
}

template<typename T>
const Array_Base <T> &Array_Base<T>::operator=(const Array_Base <T> &rhs) {
	if (this != &rhs) {
		if (size_ != rhs.size_)
			size_ = rhs.size_;

		for (int i = 0; i < this->size_; i++)
			data_[i] = rhs.data_[i];
	}

	return *this;
}

template<typename T>
T &Array_Base<T>::operator[](size_t index) {
	if (index >= this->size_) {
		throw std::out_of_range("Array index out of bound, exiting");
	}

	return this->data_[index];
}

template<typename T>
const T &Array_Base<T>::operator[](size_t index) const {
	if (index >= this->size_) {
		throw std::out_of_range("Array index out of bound, exiting");
	}
	return this->data_[index];
}

template<typename T>
bool Array_Base<T>::operator==(const Array_Base <T> &rhs) const {
	if (this != &rhs) {
		if (max_size_ != rhs.max_size_ || size_ != rhs.size_) {
			return false;
		}

		for (int i = 0; i < max_size_; ++i) {
			if (data_[i] != rhs.data_[i]) {
				return false;
			}
		}
		return true;
	}
	return true;
}

template<typename T>
bool Array_Base<T>::operator!=(const Array_Base <T> &rhs) const {
	return !(*(this) == rhs);
}

template<typename T>
T Array_Base<T>::get(size_t index) const {
	if (index >= this->size_) {
		throw std::out_of_range("Array index out of bound, exiting");
	}
	return data_[index];
}

template<typename T>
void Array_Base<T>::set(size_t index, T value) {
	if (index >= this->size_) {
		throw std::out_of_range("Array index out of bound, exiting");
	}

	data_[index] = value;
}

template<typename T>
int Array_Base<T>::find(T element) const {
	for (size_t i = 0; i < size_; ++i) {
		if (data_[i] == element) {
			return (int) i;
		}
	}
	return -1;
}

template<typename T>
int Array_Base<T>::find(T element, size_t start) const {
	if (start >= this->size_) {
		throw std::out_of_range("Array index out of bound, exiting");
	}

	for (size_t i = start; i < size_; ++i) {
		if (data_[i] == element) {
			return (int) i;
		}
	}
	return -1;
}

template<typename T>
void Array_Base<T>::fill(T element) {
	for (int i = 0; i < this->size_; ++i) {
		data_[i] = element;
	}
}
