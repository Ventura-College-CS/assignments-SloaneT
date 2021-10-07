#include <iostream>
#include <cstring>

using namespace std;

struct Students{
int id;
char *name;

};

int main()
{
    Students s1;
    s1.id = 10;
    s1.name = new char[20];
    //strcpy necessary to work with array of chars
    strcpy(s1.name, "John"); // s1 : id = 10, name = John

    Students s2;
    s2 = s1; //these end up sharing space, leading to confusion

    cout << "S2's id " << s2.id << endl;
    cout << "S2's name " << s2.name << endl;

    strcpy(s2.name, "Bill");

    cout << s1.id << endl;
    cout << s1.name << endl;


}
