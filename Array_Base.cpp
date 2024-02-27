#include <stdexcept>         // for std::out_of_bounds exception

template <typename T>
Array_Base <T>::Array_Base (void)
  : data_ (nullptr), 
  cur_size_ (0), 
  max_size_ (0) 
{

}

template <typename T>
Array_Base <T>::Array_Base (size_t length)
  : data_ (new T[length]), 
  cur_size_ (length), 
  max_size_ (length) 
{

}

template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
  : data_ (new T[length]), 
  cur_size_ (length), 
  max_size_ (length)
{
  //set each element to the filler char
	for(int i = 0;i<length;i++){
		data_[i] = fill;
	}
}

template <typename T>
Array_Base <T>::Array_Base (const Array_Base<T> & array)
 : data_ (new T[array.max_size_]), 
 cur_size_ (array.cur_size_), 
 max_size_ (array.max_size_)
{
	for(uint i = 0;i<this->cur_size_;i++){
		this->data_[i] = array[i];
	}
}

template <typename T>
Array_Base <T>::Array_Base (T * data_, size_t cur_size_, size_t max_size_)
: data_ (data_),
cur_size_ (cur_size_),
max_size_ (max_size_),
notSlice_ (false)
{ }

template <typename T>
Array_Base <T>::~Array_Base (void)
{
	if (notSlice_) {
		delete [] data_;
	}
}

template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base<T> & rhs)
{
  if(&rhs == this){
		return *this;
	}
	if(cur_size_<rhs.cur_size_){
		delete [] data_;
		data_ = new T[rhs.cur_size_];
	}
	for(int i = 0; i < rhs.size(); i++){
		this->data_[i] = rhs[i];
	}
	this->cur_size_ = rhs.cur_size_;
	this->max_size_ = rhs.cur_size_;
	return *this;
}

template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
  	if(index<this->cur_size_){
		return this->data_[index];
	}else{
		//throw an exception
		throw std::out_of_range("Index is out of range for this array.");
	}
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if(index<this->cur_size_){
		return this->data_[index];
	}else{
		//throw an exception
		throw std::out_of_range("Index is out of range for this array.");
	}
}

template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if(index<this->cur_size_){
		return this->data_[index];
	}else{
		//throw an exception
		throw std::out_of_range("Index is out of range for this array.");
	}
}

template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if(index<this->cur_size_){
		this->data_[index] = value;
	}else{
		//throw an exception
		throw std::out_of_range ("Index is out of range");
	}
}

template  <typename T>
int Array_Base <T>::find (T value) const
{
	try{
		return find(0,value);
	} catch (std::out_of_range & e) {
		return - 1;
	}
}

template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if(start>=this->cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	for(int i = start; i<this->cur_size_;i++){
		if(val==this->data_[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	//check for self equality
	if(&rhs == this){
		return true;
	}
	if(rhs.size()!=this->size()){
		return false;
	}
	for(int i = 0;i<this->cur_size_;i++){
		if(this->get(i)!=rhs.get(i)){
			return false;
		}
	}
	return true;
}

template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !(*this == rhs);
}

template <typename T>
void Array_Base <T>::fill (T value)
{
	for (int i = 0; i<this->cur_size_; i++){
		this->data_[i] = value;
	}
}

template <typename T>
void Array_Base <T>::reverse (void) {
	for (uint i = 0; i < this->cur_size_/2; i++) {
		T temp = this->data_[i];
		this->data_[i] = this->data_[cur_size_-i-1];
		this->data_[cur_size_-i-1] = temp;
	}
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin) const
{
	if (begin > cur_size_ | begin < 0) {
		throw std::out_of_range("Your slice indices are out of range.");
	}
	return Array_Base<T>(this->data_+begin, this->cur_size_ - begin, this->max_size_ - begin);
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin, size_t end) const
{
	if (begin>this->cur_size_ | begin < 0 |end > this->cur_size_ | end <= begin) {
		throw std::out_of_range("Your slice indices are out of range.");
	}
	return Array_Base<T>(this->data_+begin, end-begin, end-begin);
}
