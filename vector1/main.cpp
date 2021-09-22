#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> );
void insertOne(vector<int>, int);
void deleteOne(vector<int>, int);


int main()
{

	vector<int>::iterator it;
	vector<int> numbers = { 10, 13, 5, 7, 25};
	int 	new_number;


	printVector(numbers);
	sort(numbers.begin(), numbers.end());
	printVector(numbers);
	// 5 7 10 13 25

	// Add one value to number with keeping sorted order
	// 15
	// 5 7 10 13 15 25

	// member functions
	// insert()
	cout << "Please enter your number to insert : ";
	cin >> new_number;
	insertOne(numbers, new_number);


	cout << "Please enter your number to delete : ";
	cin >> new_number;
	deleteOne(numbers, new_number);


}

void printVector(vector<int> vec)
{
	vector<int>::iterator it;
	for(it=vec.begin(); it<vec.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

void insertOne(vector<int> numbers, int new_number)
{
	vector<int>::iterator it;
	for(it=numbers.begin(); it<numbers.end(); it++)
	{
		if ( *it > new_number)
			break;
	}
	numbers.insert(it, new_number);
	printVector(numbers);
}

void deleteOne(vector<int> numbers, int new_number)
{
    vector<int>::iterator it;
    for(it=numbers.begin(); it<numbers.end(); it++)
	{
		if ( *it == new_number)
			break;
	}

	if ( it == numbers.end())
		cout << "Value not found -- cannot be deleted \n";
	else
		numbers.erase(it);
	printVector(numbers);
}
