#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q; //Declares a queue of integers named "q"

for (int i = 0; i < 5; i++) //Declares a for loop that pushes values
	q.push(i); // 0 through 4 into queue

cout << "The size of q " << q.size() << endl; //Size of queue is 5 integers or 20 bytes

cout << " Dequeued : " << q.front() << endl; //Displays the item at the front of the queue, which is 0

q.pop(); //Removes first element in the queue, 0

cout << " Dequeued : " << q.front() << endl; //Displays the new front, which is 1

q.pop();
}
