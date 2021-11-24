#include <iostream>
#include "vector.hpp"
#include <vector>

using namespace std;

class Student {
	private:
		int id;
		string sname;
		double score[3];
  public:
		Student()
		{
		    id = 0;
            sname = "";
            score[0] = 0;
            score[1] = 0;
            score[2] = 0;
		}
		Student(int i, string s, double *sc)
		{
			id = i;
			sname = s;
			score[0] = sc[0];
			score[1] = sc[1];
			score[2] = sc[2];
		}
		void setValues(int i, string s, double *sc)
		{
			id = i;
			sname = s;
			score[0] = sc[0];
			score[1] = sc[1];
			score[2] = sc[2];
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
	cout << "Score 1" << sc[1] << endl;
	cout << "score 2" << sc[2] << endl;
}

int main()
{
	VectorQueue<Student, 5> studentQueue; //creates a vector queue of type Student, with 10 spaces

	Student s[5]; // creates an array of 10 empty student objects



	for(int i = 0; i < 5; i++){
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

	double sc[3] = {100.0, 99.9, 100.01}; //creating score arrays
	Student s1(100, "John", sc); //enqueue a student when queue is full
	studentQueue.enqueue(s1);

	for(int i = 0; i < 5; i++)
	{
		Student popstudent = studentQueue.dequeue();
		printStudent(popstudent);
	}

    Student extraPop = studentQueue.dequeue();
    printStudent(extraPop); //dequeue a student when queue is empty


}

