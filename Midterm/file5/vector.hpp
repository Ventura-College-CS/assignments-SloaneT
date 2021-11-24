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
	bool isFull() const; //These variables are constant because they do not need to be altered by the program
	bool isEmpty() const;
	T front() const;
	T back() const;
	int vsize() const;
};

#include "vector.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <class T, int size>
VectorQueue<T, size>::VectorQueue()
{
    queue.reserve(size);
}

template <class T, int size>
bool VectorQueue<T, size>::isFull() const
{
    return (queue.size() == size);
}

template <class T, int size>
bool VectorQueue<T, size>::isEmpty() const
{
	return queue.empty();
}

template <class T, int size>
void VectorQueue<T, size>::enqueue(T &el)
{
    if (isFull()){
        cout << "Queue is full!" << endl;
    } else
    {
        queue.push_back(el);
    }

}
template <class T, int size>
T VectorQueue<T, size>::dequeue()
{
    if (isEmpty())
        {
        cout << "Queue is empty!" << endl;
    } else
    {
    T el = queue.front();
	queue.erase(queue.begin());
	return el;
    }

}
template <class T, int size>
T VectorQueue<T, size>::front() const
{
	return queue.front();
}



template <class T, int size>
int VectorQueue<T, size>::vsize() const
{
	return queue.size();
}

#endif
