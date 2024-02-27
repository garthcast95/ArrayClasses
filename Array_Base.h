#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <cstring>

template<typename T>
class Array_Base {
public:
	typedef T type;

	Array_Base();

	Array_Base(size_t length);

	Array_Base(size_t length, T fill);

	Array_Base(const Array_Base<T> &arr);

	~Array_Base();

	const Array_Base<T>& operator=(const Array_Base<T> &rhs);

	T &operator[](size_t index);

	const T &operator[](size_t index) const;

	bool operator==(const Array_Base<T> &rhs) const;

	bool operator!=(const Array_Base<T> &rhs) const;

	virtual size_t size() const;

	virtual size_t max_size() const;

	virtual T get(size_t index) const;

	virtual void set(size_t index, T value);

	virtual int find(T element) const;

	virtual int find(T element, size_t start) const;

	virtual void fill(T element);

protected:
	T *data_;
	size_t size_;
	size_t max_size_;
};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif //ARRAY_BASE_H
