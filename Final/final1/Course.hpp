#ifndef COURSE_H
#define COURSE_H

#include <iostream>
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

#endif // COURSE_H
