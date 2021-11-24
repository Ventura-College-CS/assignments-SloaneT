#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
    list<int> list1(5, 100); //creates a list of 5 ints, each with the value 100
	list<int> emptyList; //creates an empty list of ints
	list<int> list3(list1.begin(), list1.end()); //iterate through list1

	queue<int, list<int> > lq(list1);

	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();
	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();
}
