#ifndef 	STACK_H //if the unique file STACK_H is not already defined
#define 	STACK_H //define it

#include <vector> //using vector STL
using namespace std;

template<class T, int capacity=30> //creates a template of class T, which has a capacity of 30 bytes
class Stack
{

private:
	vector<T>  pool; //creates a vector of type T called pool
public:
	Stack()
	{
		pool.reserve(capacity); //default constructor uses vector function reserve() to declare minimum capacity of 30 bytes
	}
	Stack(int size)
	{
		pool.reserve(size); //if a size is given, the Stack member uses reserve() to declare the given minimum capacity
	}
	T pop() //used to remove the "top" element of a stack; a vector stack treats the last element as the "top"
	{
		T val = pool.back(); // assigns a variable val of type T to the top element of stack
		pool.pop_back(); // removes the last element of stack
		return val; // returns the value which was just removed
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
