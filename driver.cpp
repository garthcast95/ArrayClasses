#include "Array.h"
#include "Stack.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include <assert.h>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Running Tests" << std::endl;
    std::cout << "Testing Array" << std::endl;
    Array<int> a;
    assert(a.size() == 0);
    assert(a.max_size() == 0);
    assert(a.find(1) == -1);

    Array<int> b;
    assert(a == b);
    a.resize(2);
    assert(a.size() == 2);
    assert(a.max_size() == 2);
    assert(a != b);

    a.set(0, 1);
    a.set(1, 2);
    const Array<int> c(10, 5);
    assert(c.size() == 10);
    assert(c.find(5) == 0);

    assert(a.size() == 2);
    assert(a.get(0) == 1);
    assert(a.get(1) == 2);
    assert(a.find(1) == 0);
    assert(a.find(2) == 1);
    assert(a.find(3) == -1);
    assert(a.find(1, 1) == -1);

    a.resize(1);
    assert(a.size() == 1);
    assert(a.max_size() == 2);

    const Array<int> f(10, 5);
    const Array<int> cp = f;
    assert(f.size() == 10);
    assert(cp.size() == 10);

    const Array<Array<double>*> arr(10);
    assert (arr.size() == 10);
    assert(arr.max_size() == 10);

    std::cout << "Testing Stack" << std::endl;
    Stack<double> st;
    assert(st.size() == 0);
    assert(st.is_empty() == true);
    try
    {
        st.pop();
        assert(false);
    }
    catch (Stack<double>::empty_exception e)
    {
        assert(true);
    }
    try
    {
        st.top();
        assert(false);
    }
    catch (Stack<double>::empty_exception e)
    {
        assert(true);
    }

    st.push(1.0);
    assert(st.size() == 1);
    assert(st.top() == 1.0);
    assert(!st.is_empty());

    st.pop();
    assert(st.size() == 0);
    assert(st.is_empty() == true);
    try
    {
        st.pop();
        assert(false);
    }
    catch (Stack<double>::empty_exception e)
    {
        assert(true);
    }
    try
    {
        st.top();
        assert(false);
    }
    catch (Stack<double>::empty_exception e)
    {
        assert(true);
    }
    for (int i=0; i<100; i++)
    {
        st.push(i);
    }

    st.clear();
    assert (st.size() == 0);
    st.push(1);
    assert(st.top() == 1);

    Stack<int> stc;
    for (int i = 0; i < 100; i++)
    {
        stc.push(i);
    }
    assert(stc.size() == 100);
    for (int i = 99; i >= 0; i--)
    {
        assert(stc.top() == i);
        stc.pop();
    }
    assert(stc.is_empty());

    const Stack<int> stcpa;

    std::cout << "Testing Fixed Array" << std::endl;

    Fixed_Array<int, 10> fa;
    fa.fill(5);
    for (int i = 0; i < 10; i++)
    {
        assert(fa.get(i) == 5);
    }
    const Fixed_Array<int, 10> fa2(5);

    for (int i = 0; i < 10; i++)
    {
        assert(fa2.get(i) == 5);
    }
    const Fixed_Array<int, 10> facpa;
    const Fixed_Array<int, 10> facpb;
    assert(facpa.size() == facpb.size());
    const Fixed_Array<int, 20> facbc(facpa);
    assert(facbc.size() == 20);

    std::cout << "Testing Queue" << std::endl;

    Queue<int> q;
    assert(q.size() == 0);

    for (int i = 0; i < 100; i++)
    {
        q.enqueue(i);
        assert(q.size() == (size_t)i + 1);
    }
    for (int i = 0; i < 100; i++)
    {
        assert(q.dequeue() == i);
        assert(q.size() == (size_t)100 - i - 1);
    }
    assert(q.is_empty());

    for (int i = 0; i < 100; i++)
    {
        q.enqueue(i);
        assert(q.size() == (size_t)i + 1);
    }
    assert(q.size() == 100);
    q.clear();
    assert(q.is_empty());
    try
    {
        q.dequeue();
        assert(false);
    }
    catch (Queue<int>::empty_exception e)
    {
        assert(true);
    }

    std::cout << "All tests pass!\n";
}
