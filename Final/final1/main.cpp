#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course
{
public:
    Course(int id, string name, int credits)
    : ID(id), name(name), credits(credits)
    {
    }
    int ID;
    string name;
    int credits;

    void printCourse()
    {
        cout << ID << "\t" << name << "\t" << credits << endl;
    }
};

int main()
{
    Course c1(111, "Jeff", 1);
    Course c2(132, "Steve", 1);
    Course c3(183, "Shave", 3);
    Course c4(214, "Dabs", 4);
    Course c5(715, "Knobs", 2);
    Course c6(126, "Shelves", 1);
    Course c7(437, "Sleeves", 5);
    Course c8(238, "Digging", 2);
    Course c9(459, "Openers", 1);
    Course c10(330, "Climbers", 3);

    vector<Course> courseVector;
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




}

void printVector(vector <Course> const &a)
{
    for(int i = 0; i < a.size(); i++)
        cout << a.at(i) << endl;
}
