#pragma once

//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
  return size_;
};

//
// is empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
  return size_ == 0;
};