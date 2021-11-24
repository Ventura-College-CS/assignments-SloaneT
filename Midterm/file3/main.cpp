#include <iostream>
#include <deque> // initial state of empty dequeue is front&rear == -1
using namespace std;

int main()
{
   int numbers[] = {30, 40, 10, 40, 50};
	deque<int> dq(numbers, numbers + 4); //creates a deque of integers with range (start of numbers([-1]), numbers[-1 +4] = numbers[3])
	cout << " Dequeued : " << dq.front() << endl; //Output the front of the deque using .front(), then remove the front element.
	dq.pop_front(); //Because it's a deque, must specify whether popping front or back.
	cout << " Dequeued : " << dq.front() << endl; // front was set to numbers[0]
	dq.pop_front();
	cout << " Dequeued from rear: " << dq.back() << endl; //The rear of the deque dq was set to numbers[3]
	dq.pop_back();
	cout << " Dequeued from rear: " << dq.back() << endl;
	dq.pop_back();
}
