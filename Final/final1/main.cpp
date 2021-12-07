#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
    Course(int ID, string name, int credits)
    : ID(ID),name(name), credits(credits)
    int ID;
    string name;
    int credits;

};

int main()
{
    Course c1;

    c1.setID(12);
}
