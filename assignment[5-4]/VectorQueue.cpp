#include "VectorQueue.h"
#include <iostream>
#include <vector>
using namespace std;

template <class T, int size = 100>
VectorQueue<T, size>::VectorQueue() //template argument invalid
{
    queue.reserve(size);
}

template <class T, int size = 100>
void VectorQueue<T, size>::enqueue(T &el)
{
	queue.push_back(el);
}
template <class T, int size = 100>
T VectorQueue<T, size>::dequeue()
{
	T el = queue.front();
	queue.pop_front();
	return el;
}
template <class T, int size = 100>
T VectorQueue<T, size>::front() const
{
	return queue.front();
}

template <class T, int size = 100>
bool VectorQueue<T, size>::isEmpty() const
{
	return queue.empty();
}

template <class T, int size = 100>
int VectorQueue<T, size>::size() const
{
	return queue.size();
}


