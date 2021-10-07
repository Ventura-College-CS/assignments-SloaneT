#include <iostream>

using namespace std;

int main()
{

    // Basic use of pointer variable
    int *ptr;
    int num;


    /*
    Students s; // assuming Students structure(similar to class) has been created
    Students *sptr;

    sptr = new Students; // points to the memory, 2 fields -- int, char[10] = 14 bytes

    sptr->id = 10;

    *sptr = s // assuming s in an instance of a class

    3 ways of saying the same thing
    s.id = 10;
    (*sptr).id = 10;
    sptr->id = 10;
    */


    ptr = &num;
    cout << *ptr << endl; // 100

    ptr = new int;
    cout << *ptr << endl; // points to new memory space (4bytes)

    *ptr = 200;

    cout << *ptr << endl; // 200

    ptr = new int[10]; // allocates 10 x 4 bytes = 40 bytes; address, address + 4, address + 8, etc.

    *ptr = 10;
    *(ptr + 4) = 20; //assigns 20 to position 4.  Memory address = address of first plus 4*4 bytes
    *(ptr + 8) = 30; // "" 30 "" "" 8

    cout << (ptr + 8);

    for(int i = 0; i < 10; i++)
        cout << *(ptr + i) << endl; //prints every element in array, some of which are unassigned "junk" variables
    cout << endl;


    int *ptr2;

    //ptr2 = new int;
    ptr2 = &int;
    *ptr2 = 20;

    cout << "Value " << *ptr2 << endl; // 20

    ptr2 = new int;
    *ptr2 = 30; // rewrites old variable but creates an extra memory space
    //leaves a dangling pointer, impossible to access -- very problematic!

    delete ptr2; // removes second memory space ^^^

    //memory space must be created!!
    //hence ptr2 = new int; // creates memory space


}
