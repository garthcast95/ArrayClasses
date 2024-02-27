// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
Array::Array (void) //initialize the array
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//setting it to zero as base
{
    data_= NULL;
    cur_size_=0;
    max_size_=0;
}

Array::Array (size_t length) //initialize the array length
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

    // COMMENT There is no need to initialize the array with a default value because (1) the
    // user may not want to initialize it with the value you chose and (2) if they did they would
    // use the fill constructor.
    //moved to fill constructor and initialized member var
{
    data_= (char*)malloc(sizeof(char)*length);
    for (unsigned int i=0; i<length; i++)
    {
        data_[i] = 0;
    }
    cur_size_ = length;
    max_size_ = length;

}


Array::Array (size_t length, char fill)
{
    // COMMENT Initialize all member variables in the base member initialization section
    // of the constructor on its own line. Otherwise, it is hard to know what initialization
    // has an error since it will not have its own unique line number.
    // COMMENT This is not the correct way to fill the contents of the array with
    // the specified fill character.
    //filling it in
    data_ = (char*)malloc(sizeof(char)*length);
    for (unsigned int i=0; i<length; i++)
    {
        data_[i] = fill;
    }
    cur_size_ = length;
    max_size_ = length;


}


Array::Array (const Array & array)
    // COMMENT Initialize all member variables in the base member initialization section
    // of the constructor on its own line. Otherwise, it is hard to know what initialization
    // has an error since it will not have its own unique line number.
    // COMMENT You have not allocated space for the array.

{
    cur_size_ = array.size();
    max_size_ = array.size();
    data_ = (char*)malloc(sizeof(char)*array.size());
    for (size_t i=0; i<cur_size_; i++)
    {
        data_[i] = array[i];
    }
}

Array::~Array (void) //Destructor here
{
    // COMMENT You have a memory leak because you did not delete
    // the data_ array.
    //Added deconstructor

    free(data_);
}

const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Check for self assignment first.
    // COMMENT Your array will have a runtime failure if the number of elements on the
    // rhs is more than the max size of this array.
    //added assignment operator
    //assigns the array also to the rhs
    if (*this != rhs)
    {
        cur_size_ = rhs.size();
        max_size_ = rhs.size();
        data_ = (char*)malloc(sizeof(char)*rhs.size());
        for (size_t i=0; i<cur_size_; i++)
        {
            data_[i] = rhs[i];
        }
    }
    return *this;
}



char & Array::operator [] (size_t index)
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //check if index is valid then throw exception
{
    if (index >= this->cur_size_ || index < 0) {
        //cout << "Array index out of bound, exiting";

        throw std::out_of_range("Array index out of bound, exiting");
    }
    return this->data_[index];


}

const char & Array::operator [] (size_t index) const
    // COMMENT This method is not implemented.
    //added for asgn 2
{
    if (index >= this->cur_size_ || index < 0) {
        //  cout << "Array index out of bound, exiting";
        throw std::out_of_range("Array index out of bound, exiting");
    }
    return this->data_[index];
}


char Array::get (size_t index) const
{
    // COMMENT This method is not implemented.
    //added for asgn 2
    if (index >= this->cur_size_ || index < 0) {
        //  cout << "Array index out of bound, exiting";
        throw std::out_of_range("Array index out of bound, exiting");
    }
    return data_[index];
}

void Array::set (size_t index, char value)
    //added for asgn 2
{
    if (index >= this->cur_size_ || index < 0) {
        //  cout << "Array index out of bound, exiting";
        throw std::out_of_range("Array index out of bound, exiting");
    }
    data_[index] = value;
}

void Array::resize (size_t new_size)//compare from above
    // COMMENT This method is not implemented.
    //added for asgn 2
{
    if (new_size > this->max_size_)
    {
        char* copy = (char*)malloc(sizeof(char)*new_size);
        for (size_t i=0; i<size(); i++)
        {
            copy[i] = data_[i];
        }
        for (size_t i=cur_size_; i<new_size; i++)
        {
            copy[i] = 0;
        }
        free(data_);
        data_ = copy;
        max_size_ = new_size;
    }
    cur_size_ = new_size;
}

int Array::find (char ch) const

    // COMMENT This method is not implemented.
    //added for asgn 2
{
    for(int i=0; i<cur_size_; i++)
    {
        if (data_[i] == ch)
        {
            return i;
        }
    }
    return -1;
}


int Array::find (char ch, size_t start) const
    // COMMENT This method is not implemented.
    //added for asgn 2
{
    if (start >= size() || start < 0) {
        throw std::out_of_range("Index out of bounds.");
    }
    for (size_t i = start; i < cur_size_; i++)
    {
        if (ch == data_[i])
        {
            return i;
        }
    }
    return -1;
}

bool Array::operator == (const Array & rhs) const
    // COMMENT This method is not implemented.
{
    if (cur_size_ != rhs.size())
    {
        return false;
    }
    for (size_t i=0; i<cur_size_; i++)
    {
        if (data_[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}



bool Array::operator != (const Array & rhs) const
    // COMMENT This method is not implemented.
{
    return !(*this == rhs);
}

void Array::fill (char ch)
{
    // COMMENT This method is not implemented.
    for(size_t i=0;i<cur_size_;i++)
    {
        data_[i] = ch;
    }
}

void Array::shrink (void)
{
    // COMMENT This method is not implemented.
    size_t j = 0;
    for (size_t i=0; i<size(); i++) {
        if (data_[i] != 0)
        {
            data_[j] = data_[i];
            j++;
        }
    }
    char* new_data = (char*)malloc(sizeof(char)*j);
    for (size_t i=0; i<j; i++) {
        new_data[i] = data_[i];
    }
    free(data_);
    cur_size_ = j;
    max_size_ = j;
    data_ = new_data;
}

void Array::reverse (void)
    // COMMENT This method is not implemented.
{
    int i=0;
    int j = cur_size_-1 ;
    while (i < j)
    {
        char temp = data_[i];
        data_[i] = data_[j];
        data_[j] = temp;
        i++;
        j--;
    }
}


Array Array::slice (size_t begin) const
{
    // COMMENT This method is not implemented.
     if (begin >= cur_size_ || begin < 0) {
        return Array();
    }
    Array sl(cur_size_-begin);

    for(size_t i=0;i<cur_size_-begin;i++)
    {
        sl[i] = data_[i+begin];
    }
    return sl;
}

Array Array::slice (size_t begin, size_t end) const
{
    // COMMENT This method is not implemented.
    if (begin >= cur_size_ || begin < 0 || begin >= end || end > cur_size_) {
        return Array();
    }
    Array sl(end - begin);

    for(int i=0; i<end-begin; i++)
    {
        sl[i] = data_[i+begin];
    }
    return sl;
}
