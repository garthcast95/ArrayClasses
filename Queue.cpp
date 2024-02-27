#pragma once

/// Default constructor.
template <typename T>
Queue<T>::Queue (void)
{
    size_ = 0;
    front_ = -1;
    back_ = -1;
    data_.resize(10);
};

/// Copy constructor.
template <typename T>
Queue<T>::Queue (const Queue & q)
{
    data_ = q.data_;
    size_ = q.size_;
    front_ = q.front_;
    back_ = q.back_;
};

/// Destructor.
template <typename T>
Queue<T>::~Queue (void)
{

};

/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template <typename T>
const Queue<T> & Queue<T>::operator = (const Queue & rhs)
{
    if (this != &rhs)
    {
        size_ = rhs.size_;
        front_ = rhs.front_;
        back_ = rhs.back_;
        data_ = rhs.data_;
    }
    return *this;
};

/**
 * Adds the element to the end of the queue.
 *
 * @param[in]      element       Element to add to the list
 */
template <typename T>
void Queue<T>::enqueue (T element)
{
    size_++;
    back_++;
    if (back_ == (int)data_.max_size())
    {
        back_ = 0;
    }
    if (back_ == front_)
    {
        size_t before = data_.max_size();
        size_t after = data_.max_size()*2;
        data_.resize(after);
        for (size_t i=front_; i<before; i++)
        {
            data_.set(i+before, data_.get(i));
        }
        front_ = front_+before;
    }
    data_.set(back_, element);
    if (front_ == -1)
    {
        front_ = 0;
    }
};

/**
 * Removes the element at the from of the list. If there is not elements in
 * the queue, this method throws empty_exception.
 *
 *
 * @exception      empty_exception    The queue is empty.
 */
template <typename T>
T Queue<T>::dequeue (void)
{
    if (is_empty())
    {
        throw(empty_exception());
    }
    if (front_ == (int)data_.max_size())
    {
        front_ = 0;
    }
    T first = data_.get(front_);
    front_++;
    size_--;

    return first;
}

/// Remove all elements from the queue.
template <typename T>
void Queue<T>::clear (void)
{
    size_ = 0;
    data_.resize(0);
}
