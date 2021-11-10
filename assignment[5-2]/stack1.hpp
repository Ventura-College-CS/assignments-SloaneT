#ifndef 	STACK_H
#define 	STACK_H

#include <vector>
using namespace std;

template<class T, int capacity=30>
class Stack
{

private:
	vector<T>  pool;
public:
	Stack()
	{
		pool.reserve(capacity);
	}
	Stack(int size)
	{
		pool.reserve(size);
	}
	T pop()
	{
		T val = pool.back();
		pool.pop_back();
		return val;
	}
	void push(T v)
	{
		pool.push_back(v);
	}
	T isEmpty() const
	{
		return pool.empty();
	}
	T topEl() const
	{
		return pool.back();
	}


};

#endif

