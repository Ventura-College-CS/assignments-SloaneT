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

int main()
{
    vector<Course> courseVector;

    Course c1(12, "Sleeves", 13);



    return 0;
}

