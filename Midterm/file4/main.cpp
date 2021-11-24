#include <iostream>
#include <list>
#include <queue>
#include <deque>

using namespace std;

int main()
{
    list<int> list1(3, 1200); //creates a list of 3 ints, each with the value 1200
	list<int> emptyList; //creates an empty list of ints
	list<int> list3(list1.begin(), list1.end()); //iterate through list1

	queue<int, list<int> > lq(list1); //declares a queue of int lists, initialized to copy of list1
    queue<int, list<int> > emptyqueue; //empty queue with list as underlying container

	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();
	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();
}
