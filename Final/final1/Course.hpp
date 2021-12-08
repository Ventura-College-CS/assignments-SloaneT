#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

// Course is created and implemented within the same file because of its simplicity

class Course
{
private:
        int ID; // course ID
        string name;
        int credits;

public:
    Course() // default constructor
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

    void setValues(int i, string n, int c) // setter for all values
    {
        ID = i;
        name = n;
        credits = c;
    }

    // getters

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
