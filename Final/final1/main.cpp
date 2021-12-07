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

    //    for(int i = 0; i < 10; i++)
//    {
//        cout << courseVector[i].getCredits() << endl;
//        cout << courseVector[i].getName() << endl;
//        cout << courseVector[i].getID() << endl;
//    }


    return 0;
}

