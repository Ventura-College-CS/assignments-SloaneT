#ifndef VECTORQUEUE_HPP
#define VECTORQUEUE_HPP

#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T, int size = 100>
class VectorQueue
{
private:
	vector<T> queue;

public:
	VectorQueue();
	void enqueue(T &el);
	T dequeue();
	bool isEmpty() const;
	T front() const;
};



#endif
