#include <iostream>
#include "vector.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Student {
	private:
		int id;
		string sname;
		double score[2];
  public:
		Student()
		{
		    id = 0;
            sname = "";
            score[0] = 0;
            score[1] = 0;
		}
		Student(int i, string s, double *sc)
		{
			id = i;
			sname = s;
			score[0] = sc[0];
			score[1] = sc[1];
		}
		void setValues(int i, string s, double *sc)
		{
			id = i;
			sname = s;
			score[0] = sc[0];
			score[1] = sc[1];
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
	cout << "Score 0 " << sc[0] << endl;
	cout << "Score 1" << sc[1]<< endl;
}

int main()
{

    srand((int)time(0));

	VectorQueue<int, 10> arrayQueue;

	for (int i = 0; i < 10; i++)
    {
        int n = (rand() % 100) + i; //assigns n to a random value
        arrayQueue.enqueue(n);  //enqueues the new value of n
    }
    for (int i = 0; i < 10; i++)
    {
        int popnumber = arrayQueue.dequeue(); //assigns the front element of queue to an int variable
        cout << popnumber << endl;
    }




	VectorQueue<Student, 10> studentQueue; //creates a vector queue of type Student, with 10 spaces



	Student s[10]; // creates an array of 10 empty student objects



	for(int i = 0; i < 3; i++){
        int id;
        string name;
        double score[2];
        cout << "Please enter id number for student " << i + 1 << ": " << endl;
        cin >> id;

        cout << "Please enter name " << i + 1 << ": " << endl;
        cin >> name;

        cout << "Please enter both scores, one at a time for student " << i + 1 << ": " << endl;
        cin >> score[0] >> score[1];

        s[i].setValues(id, name, score);
	    studentQueue.enqueue(s[i]);
	}

	double sc[2] = {100.0, 99.9}; //creating score arrays
	Student s1(100, "John", sc); //enqueue a student when queue is full
	studentQueue.enqueue(s1);

	for(int i = 0; i < 3; i++)
	{
		Student popstudent = studentQueue.dequeue();
		printStudent(popstudent);
	}

    Student extraPop = studentQueue.dequeue();
    printStudent(extraPop); //dequeue a student when queue is empty




}
