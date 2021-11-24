#include <iostream>
#include "vector.hpp"
#include <vector>

using namespace std;

class Student {
	private:
		int id;
		string sname;
		double score[3]; //an array of 3 doubles
  public:
		Student()
		{
		    id = 0; //default value = 0
            sname = ""; // default value is empty
            for(int i = 0; i < 3; i++) //for loop used to assign all three scores a default value 0
            {
                score[i] = 0;
            }
		}
		Student(int i, string s, double *sc) //accepts an integer, a string, and a pointer to the address of score
		{
			id = i;
			sname = s;
			for(int i = 0; i < 3; i++)
            {
                score[i] = sc[i];
            }
		}
		void setValues(int i, string s, double *sc)
		{
			id = i;
			sname = s;
			for(int i = 0; i < 3; i++)
            {
                score[i] = sc[i];
            }
		}
		int getID()
		{
		    return id;
        }
		string getName()
        {
			return sname;
		}
		double *getScore() //points to the address of the sc array
		{
			return score;
		}
};

void printStudent(Student &s)
{
	double	 *sc; //points to the address of each member of the sc array
	cout << "S ID " << s.getID()<< endl;
	cout << "S name " << s.getName()<< endl;
	sc = s.getScore();
	for(int i = 0; i < 3; i++)
    {
        cout << "Score " << i + 1 << ": " << sc[i] << endl;
    }
}

int main()
{
	VectorQueue<Student, 5> studentQueue; //creates a vector queue of type Student, with 5 spaces

	Student s[5]; // creates an array of 5 empty student objects



	for(int i = 0; i < 5; i++) //for loop used to receive student information
    {
        int id;
        string name;
        double score[3];
        cout << "Please enter id number for student " << i + 1 << ": " << endl;
        cin >> id;

        cout << "Please enter name " << i + 1 << ": " << endl;
        cin >> name;

        cout << "Please all three scores, one at a time for student " << i + 1 << ": " << endl;
        cin >> score[0] >> score[1] >> score[2];

        s[i].setValues(id, name, score);
	    studentQueue.enqueue(s[i]);
	}

    cout << "Current size of student queue: " << studentQueue.vsize() << endl;

	double sc[3] = {100.0, 99.9, 100.01}; //creating score arrays
	Student s1(100, "John", sc); //create a sixth student
	studentQueue.enqueue(s1); //attempt to enqueue when queue is full

	for(int i = 0; i < 5; i++) //dequeue all five students
	{
		Student popstudent = studentQueue.dequeue();
		printStudent(popstudent);
	}

    Student extraPop = studentQueue.dequeue();
    printStudent(extraPop); //attempt to dequeue a student when queue is empty


}

