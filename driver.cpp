#include "Array.h"
#include <assert.h>
#include <exception>
#include <iostream>

int main (int argc, char * argv [])
{
  std::cout << "Running Tests..." << std::endl;

  std::cout << "Testing Initialization" << std::endl;
  // TODO Add code here to test your Array class.
  Array a1;
  assert(a1.size() == 0);
  assert(a1.max_size() == 0);

  Array a2(10);
  assert(a2.size() == 10);
  assert(a2.max_size() == 10);
  for (size_t i=0; i<10; i++)
  {
    assert(a2[i] == 0);
  }

  Array a3(10, 'a');
  assert(a3.size() == 10);
  assert(a3.max_size() == 10);
  for (size_t i=0; i<10; i++)
  {
    assert(a3[i] == 'a');
  }

  Array a4 = a3;
  assert(a4.size() == 10);
  assert(a4.max_size() == 10);
  for (size_t i=0; i<10; i++)
  {
    assert(a4[i] == 'a');
  }

  Array a5(a4);
  assert(a5.size() == 10);
  assert(a5.max_size() == 10);
  for (size_t i=0; i<10; i++)
  {
    assert(a5[i] == 'a');
  }

  std::cout << "Testing Get" << std::endl;
  for (size_t i=0; i<10; i++)
  {
    assert(a5.get(i) == 'a');
  }

  std::cout << "Testing Resize" << std::endl;
  a5.resize(20);
  assert (a5.size() == 20);
  assert (a5.max_size() == 20);
  for (size_t i=0; i<10; i++)
  {
    assert(a5[i] == 'a');
  }
  for (size_t i = 10; i<20; i++)
  {
    assert(a5[i] == 0);
  }

  a5.resize(5);
  assert(a5.size() == 5);
  assert(a5.max_size() == 20);
  for (size_t i=0; i<5; i++)
  {
    assert(a5[i] == 'a');
  }
  try
  {
    a5[5];
    std::cout << "Test Failed. Exiting.\n";
  }
  catch (std::exception& e) {}

  std::cout << "Testing Find" << std::endl;
  Array a6(10);
  for (size_t i=0; i<10; i++)
  {
    a6[i] = 'a'+i;
  }
  for (size_t i=0; i<10; i++)
  {
    assert(a6.find('a'+i) == i);
  }
  assert(a6.find('z') == -1);

  std::cout << "Testing Slice" << std::endl;
  Array slice = a6.slice(4);
  for (size_t i=0; i<6; i++)
  {
    assert(slice[i] == 'a'+4+i);
  }

  std::cout << "Testing Reverse" << std::endl;
  a6.reverse();
  for (size_t i=0; i<10; i++)
  {
    assert(a6[i] = 'a'+9-i);
  }

  std::cout << "All Tests Passed." << std::endl;

  return 0;
}
