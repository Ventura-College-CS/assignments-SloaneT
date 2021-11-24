#ifndef VECTORQUEUE_HPP
#define VECTORQUEUE_HPP

#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T, int size = 100> //templates are used throughout this class to allow multiple data types to be used
class VectorQueue
{
private:
	vector<T> queue; //declare vector of type T called queue

public:
	VectorQueue(); //constructor
	void enqueue(T &el); //enqueue, accepts the address of an element type T, adds it to the back of the queue
	T dequeue();  //removes the first element of the queue
	//The following variables are constant because they do not need to be altered by the program
	bool isFull() const; //checks whether queue is full
	bool isEmpty() const; //checks whether queue is empty
	T front() const; //returns the front element of the queue
	T back() const; //returns back element
	int vsize() const; //returns the number of elements in the queue
};

template <class T, int size>
VectorQueue<T, size>::VectorQueue()
{
    queue.reserve(size); //when instantiating a VectorQueue object, the vector reserves enough space to contain every element
}

template <class T, int size>
bool VectorQueue<T, size>::isFull() const
{
    return (queue.size() == size); //if the capacity of the queue is equal to the number of elements in the queue, it is full
}

template <class T, int size>
bool VectorQueue<T, size>::isEmpty() const
{
	return queue.empty(); //if there are no elements in queue, returns true
}

template <class T, int size>
void VectorQueue<T, size>::enqueue(T &el)
{
    if (isFull()){
        cout << "Queue is full!" << endl; //cannot enqueue beyond a certain limit
    } else
    {
        queue.push_back(el); //pushes the element to the back of the queue
    }

}
template <class T, int size>
T VectorQueue<T, size>::dequeue()
{
    if (isEmpty())
        {
        cout << "Queue is empty!" << endl; //cannot dequeue if queue is empty
    } else
    {

    T el = queue.front(); // element of type T is assigned as the first member of queue
    queue.erase(queue.begin()); // erases the value at the first iteration
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
