#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyCompareFunction
{
public:
	int operator()(const int &lhs, const int &rhs) //override () operator, takes references of both operands, assigns them to lhs and rhs
	{
		int l, r; //declare two int variables, l and r
		l = lhs; //l is equal to the remainder of lhs / 10
		r = rhs; //r is equal to remainder of rhs / 10
		return l < r; // gives priority to larger number
	}
};

class MyCompareFunction2
{
public:
	int operator()(const int &lhs, const int &rhs) //override () operator, takes references of both operands, assigns them to lhs and rhs
	{
		int l, r; //declare two int variables, l and r
		l = lhs;
		r = rhs;
		return l > r; // gives priority to lower number
	}
};

int main()
{
	priority_queue<int, vector<int>, MyCompareFunction> pq; //declares a priority queue pq, made of vectors filled with integers.
	   // Overrides STL compare function with custom class to allow for easy modification

	pq.push(31); //push values to the queue which are automatically sorted
	pq.push(45);
	pq.push(29);



	while (!pq.empty()) //while the priority queue is NOT empty,
	{
		cout << "Popped Value : " << pq.top() << endl; //print the value to be popped using .top()
		pq.pop(); //pop the value AFTER printing
	}
}
