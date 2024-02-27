   // COMMENT You are supposed to use your array class.
#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_
// include the source file since template class

#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
    const char* what() const throw()
    {
      return "Empty queue exception";
    }
  };

  /// Default constructor.
  Queue (void);
  /// Copy constructor.
  Queue (const Queue & s);
  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue<T> & operator = (const Queue & rhs);

  /**
   * Adds the element to the end of the queue.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Removes the element at the from of the list. If there is not elements in
   * the queue, this method throws empty_exception.
   *
   * @exception      empty_exception    The stack is empty.
   */
  T dequeue (void);

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  // add member variable here
  int size_;
  int front_;
  int back_;
  Array<T> data_;
};

#include "Queue.cpp"
#include "Queue.inl"

#endif
