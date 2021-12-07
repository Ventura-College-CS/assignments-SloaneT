#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course
{
private:
        int ID;
        string name;
        int credits;

public:
    Course()
    {
        ID = 0;
        name = "";
        credits = 0;
    }

    Course(int id, string n, int c)
    {
        ID = id;
        name = n;
        credits = c;
    }

    void setValues(int i, string n, int c)
    {
        ID = i;
        name = n;
        credits = c;
    }

    int getID()
    {
        return ID;
    }

    string getName()
    {
        return name;
    }

    int getCredits()
    {
        return credits;
    }



};

void printCourse(Course &c)
    {
        cout << "Course ID: " << c.getID() << endl;
        cout << "Course Name: " << c.getName() << endl;
        cout << "Course Credits: " << c.getCredits() << endl;
    }

void qsort(vector<Course>, int, int);
int partition(vector<Course>, int, int);

int main()
{
    vector<Course> courseVector;

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




    courseVector.push_back(c1);
    courseVector.push_back(c2);
    courseVector.push_back(c3);
    courseVector.push_back(c4);
    courseVector.push_back(c5);
    courseVector.push_back(c6);
    courseVector.push_back(c7);
    courseVector.push_back(c8);
    courseVector.push_back(c9);
    courseVector.push_back(c10);


        for(int i = 0; i < 10; i++)
    {
        cout << courseVector[i].getCredits() << endl;
        cout << courseVector[i].getName() << endl;
        cout << courseVector[i].getID() << endl;
    }

    qsort(courseVector, 0, 9);

            for(int i = 0; i < 10; i++)
    {
        cout << courseVector[i].getCredits() << endl;
        cout << courseVector[i].getName() << endl;
        cout << courseVector[i].getID() << endl;
    }

    return 0;
}

void qsort(vector<Course> vec, int first, int last)
{
	int pivot_idx;

	// Base Condition
	if ( first >= last )
		return;

	pivot_idx = partition(vec, first, last);
	qsort(vec, first, pivot_idx-1); //
	qsort(vec, pivot_idx+1, last);  //

}

int partition(vector<Course> vec, int first, int last)
{
	int pivot = vec[last]; // cannot convert 'Course' to 'int'
	int i = -1;
	for (int j = 0; j < last; j++)
	{
		if (vec[j].getID() < vec[pivot].getID())
			swap(vec[i + 1], vec[j]);
	}
	swap(vec[i + 1], vec[last]);
	return i + 1;
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

    // We reach here when element is not
    // present in array
    return -1;
}
