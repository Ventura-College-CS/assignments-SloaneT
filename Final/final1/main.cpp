
// Please note, the following code is intended to answer Final Exam questions 1 and 2.

// First it implements a recursive quick sort function for use on a custom class Course. (Question 2)
// After sorting a vector of type Course based on ID,
//  the program uses a custom binary search function to search the vector using ID as a parameter. (Question 1)

#include <iostream>
#include <vector>
#include "Course.hpp"
using namespace std;


void printCourse(Course &c) // Pass a Course object by reference as an argument
    {
        cout << "Course ID: " << c.getID() << endl; // Uses getters to access object attributes
        cout << "Course Name: " << c.getName() << endl;
        cout << "Course Credits: " << c.getCredits() << endl;
        cout << " " << endl;
    }

// Initializing functions
void qsort(vector<Course>&, int, int);
int partition(vector<Course>&, int, int);

int binarySearch(vector<Course>, int l, int r, int target);

int main()
{
    vector<Course> courseVector; //instantiate a vector of type Course to contain Course objects

    // instantiate ten unique Course objects
    Course c1(134, "Sleeves", 3);
    Course c2(343, "Bottles", 2);
    Course c3(332, "Cowboys", 4);
    Course c4(828, "Ropes", 1);
    Course c5(133, "Vitality", 3);
    Course c6(333, "Hunger", 4);
    Course c7(777, "Lexicons", 2);
    Course c8(949, "Orthography", 3);
    Course c9(805, "Cataclysms", 4);
    Course c10(123, "Expectations", 2);

 //Initializer list: first argument is an iterator to the element before which we will insert our elements.
 // Inserting before the end() iterator, therefore appending values to the end of vector
    courseVector.insert(courseVector.end(), { c1, c2, c3, c4, c5, c6, c7, c8, c9, c10});


    for(int i = 0; i < 10; i++) // Loop used to print the values of each object in the vector before sorting
    {
        printCourse(courseVector[i]);
    }

    const int N = 10; // const is used to ensure that N will not be altered by the program

    qsort(courseVector, 0, N-1); // Calling the quick sort function on courseVector, with indexes 0 and 9 as 'first' and 'last' arguments, respectively

    for(int i = 0; i < 10; i++) // Print values of each object in vector after sorting
    {
        printCourse(courseVector[i]);
    }


    int result = binarySearch(courseVector, 0, 9, 949); // A basic set of instructions to help make the result of binarySearch more readable

    if(result != -1)
    {
        cout << "Target found at index: " << result;
    } else
    {
        cout << "Target not found." << endl;
    }

    return 0;
}

void qsort(vector<Course>& vec, int first, int last) // Very important to pass the courseVector by reference, to modify the actual values
{
	int pivot_idx; // The pivot is used to divide the vector into increasingly smaller sections which can be sorted individually

	// Base Condition, prevents algorithm from running eternally
	if ( first >= last ) // If the leftmost index is >= the rightmost, then there is only one value remaining and division is no longer possible
		return;

	pivot_idx = partition(vec, first, last); // the pivot is assigned to the result of the partition function
	qsort(vec, first, pivot_idx-1); // Sorting the vector on the left side of the pivot index
	qsort(vec, pivot_idx+1, last);  // Sorting the vector on the right side of the pivot index

}

int partition(vector<Course>& vec, int first, int last)
{
	Course pivot = vec[last]; //pivot is set to the vector member ID value at index "last", aka the rightmost index
	int i = (first - 1);
	for (int j = first; j < last; j++) //iterates through each index of the partitioned vector
	{
		if (vec[j].getID() < pivot.getID()) //if courseVector ID at index "j" is less than courseVector ID at index "last"
			swap(vec[++i], vec[j]);
			 //swap courseVector member at index [++i] with courseVector member at index j.
			 // ***i is incremented after each swap, very important***
	}
	swap(vec[i + 1], vec[last]); // When for loop ends, swap courseVector member at the index of
	// wherever the loop ended with the pivot
	return (i + 1); // The iteration at which the loop ended becomes the new partition, aka the new pivot index
}

int binarySearch(vector<Course> vec, int l, int r, int target)
{
    if (r >= l)
    {
        int mid = (l + r) / 2; // mid = (leftmost index + rightmost index) / 2

        // If the target is present at the middle
        if (vec[mid].getID() == target)
            return mid;

        // If target is smaller than mid, then
        // it can only be present in left sub-array
        if (target < vec[mid].getID())
            return binarySearch(vec, l, mid - 1, target); //implements selfsame function, but replaces r with mid-1

        // Else the element can only be present
        // in right sub-array
        return binarySearch(vec, mid + 1, r, target); //implements selfsame function, replaces l with mid+1
    }

    // We reach here if element is not present in array
    return -1;
}
