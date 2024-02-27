template <typename T>
Array<T>::Array()
: Array_Base<T>() { }

template <typename T>
Array<T>::Array(size_t length)
: Array_Base<T>(length) { }

template <typename T>
Array<T>::Array(size_t length, T fill)
: Array_Base<T>(length, fill) { }

template <typename T>
Array<T>::Array(const Array & arr)
: Array_Base<T>(arr) {}

template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size > this->cur_size_) {
		// if the new array needs more space
		if (new_size > this->max_size_){
			T * temp = new T[new_size];
			for (uint i = 0; i<this->cur_size_; i++){
				temp[i] = this->data_[i];
			}
			//delete old array
			delete [] this->data_;
			//reassign data_ to temp
			this->data_ = temp;
			this->cur_size_ = new_size;
			this->max_size_ = new_size;
		}
		//if didn't need more space, just reset cur_size
		this->cur_size_ = new_size;
	} else if (new_size < this->cur_size_) {
		this->cur_size_ = new_size;
	}
}

template <typename T>
void Array<T>::shrink (void)
{
	if (this->max_size_>this->cur_size_) {
		T * temp = new T[this->cur_size_];
		for (int i = 0; i<this->cur_size_; i++) {
			temp[i] = this->data_[i];
		}
		//delete old array
		delete [] this->data_;
		//reset data_
		this->data_ = temp;
		this->max_size_ = this->cur_size_;
	}
}

template <typename T>
const Array<T> & Array<T>::operator = (const Array<T> & rhs) {
	  if(&rhs == this){
		return *this;
	}
	if(this->cur_size_<rhs.cur_size_){
		delete [] this->data_;
		this->data_ = new T[rhs.cur_size_];
	}
	for(int i = 0; i < rhs.size(); i++){
		this->data_[i] = rhs[i];
	}
	this->cur_size_ = rhs.cur_size_;
	this->max_size_ = rhs.cur_size_;
	return *this;
}
