// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//#include "Array.h"
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
//    data_= new char [length];
//    cur_size_ = length;
}

//
// Array (size_t, char)
//
template<typename T>
Array<T>::Array(size_t length, T fill)
		: Array_Base<T>(length, fill) {
//    data_ = new char [length];
//    cur_size_ = length;
//
//for(int i=0;i<length;i++)
//    {
//        data_[i] = fill;
//
//    }
}

//
// Array (const Array &)
//
template<typename T>
Array<T>::Array(const Array <T> &array)
		: Array_Base<T>(array) {
//    strcpy(this->data_,array.data_);
//    cur_size_ = array.cur_size_;
//    max_size_ = array.max_size_;
//	for (size_t i = 0; i < array.size(); ++i) {
//		this->data_[i] = array.data_[i];
//	}
}

//
// ~Array
//
template<typename T>
Array<T>::~Array(void) {
//    delete (data_);
//    data_ = NULL;
//    cur_size_=0;
//    max_size_ = 0;
}

//
// operator =
//
//template <typename T>
//const Array <T> & Array <T>::operator = (const Array<T> & rhs)
//{
//    this->data_ = new char[rhs.cur_size_];
//            strcpy(this->data_,rhs.data_);
//        this->cur_size_ = rhs.cur_size_;
//        this->max_size_  =  rhs.max_size_;
//            return *this;
//}

//
// operator []
//
//template <typename T>
//T & Array <T>::operator [] (size_t index)
//{
//    if (index >= this->cur_size_) {
//        throw std::out_of_range("Array index out of bound, exiting");
//    }
//
//    return this->data_[index];
//}

//
// operator []
//
//template <typename T>
//const T & Array <T>::operator [] (size_t index) const
//{
//    if (index >= this->cur_size_) {
//        throw std::out_of_range("Array index out of bound, exiting");
//    }
//    return this->data_[index];
//}

//
// get
//
//template <typename T>
//T Array <T>::get (size_t index) const
//{
//    return data_[index];
//}

//
// set
//
//template <typename T>
//void Array <T>::set (size_t index, T value)
//{
//   if(ind < max_size_ && ind >= 0)
//    {
//    data_[ind] = data;
//    cur_size_++;
//    }
//}

//
// resize
//
template<typename T>
void Array<T>::resize(size_t new_size) {
//	if (new_size <= this->size_) {
//		return;
//	}
//
//	T temp[this->size_];
//
//	for (size_t i = 0; i < new_size; ++i) {
//		temp[i] = this->data_[i];
//	}
//
//	delete[] this->data_;
//	this->data_ = new T[new_size];
//	this->max_size_ = new_size;
//	this->size_ = new_size;
//
//	for (int i = 0; i < this->size_; ++i) {
//		this->data_[i] = temp[i];
//	}

	if (new_size < this->size_) {
		this->size_ = new_size;
	} else if (new_size > this->size_) {
		T *new_array_ = this->data_;

		for (size_t index = 0; index < new_size; ++index) {
			if (index <= this->size_) {
				this->data_[index] = new_array_[index];
			}
		}

		this->size_ = new_size;
		this->max_size_ = new_size;
	}

//    char * save_array;
//    if(new_size < cur_size_)
//    {
//        return;
//    }
//    if(new_size == cur_size_)
//    {
//        return;
//    }
//    save_array = new char[cur_size_];
//    strcpy(save_array,this->data_);
//
//    delete (data_);
//    data_=NULL;
//        data_ = new char [new_size];
//        for(int i=0;i<cur_size_;i++)
//        {
//         data_[i] = save_array[i];
//        }
//
//    cur_size_ = new_size;
}

//
// find (char)
//
//template  <typename T>
//int Array <T>::find (T value) const
//{
//    for(int i=0;i<cur_size_;i++)
//        {
//         if (data_[i] == ch )   return i;
//
//        }
//
//    return -1;
//}

//
// find (char, size_t)
//
//template <typename T>
//int Array <T>::find (T val, size_t start) const
//{
//        for (size_t i = start; i < cur_size_; i++)
//    {
//        if (ch == data_[i])
//            return i;
//    }
//    return -1;
//}

//
// operator ==
//
//template <typename T>
//bool Array <T>::operator == (const Array & rhs) const
//{
//    if (strcmp(data_,rhs.data_)==0 && rhs.cur_size_ == this->cur_size_ && rhs.max_size_ == max_size_)
//    {
//        return true;
//    }
//
//    else
//    {
//        return false;
//    }
//}

//
// operator !=
//
//template <typename T>
//bool Array <T>::operator != (const Array & rhs) const
//{
//     if(strcmp(data_,rhs.data_)==0 && rhs.cur_size_ == this->cur_size_ && rhs.max_size_ == max_size_)
//     {
//
//         return false;
//     }
//    return true;
//}

//
// fill
//
//template <typename T>
//void Array <T>::fill (T value)
//{
//for(int i=0;i<cur_size_;i++)
//    {
//        data_[i] = ch;
//
//    }
//}
