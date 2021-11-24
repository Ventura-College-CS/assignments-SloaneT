#include <iostream>
#include <queue>

using namespace std;

const int NUM_STUDENTS = 10;
const int NUM_SCORES = 3;
class Students
{
private:
	int sid;
	string sname;
	vector<double> score; // score is a vector of doubles

public:
	Students() : sid(0), sname() {}
	Students(int id, string name, double s0, double s1, double s2)
	{
		sid = id;
		sname = name;
		score.push_back(s0); //pushes to the back of the queue
		score.push_back(s1);
		score.push_back(s2);
	}
	//getters
	int getSid() const { return sid; }

	string getSname() const { return sname; }

	vector<double> const &getScore() const { return score; }

	//setters
	void setSid(int id) { sid = id; }

	void setSname(string name) { sname = name; }

	void setScore(double s0, double s1, double s2)
	{
		score.clear(); //removes and destroys all elements of the score vector
		score.push_back(s0);
		score.push_back(s1);
		score.push_back(s2);
	}
	void printStudent() const //const assures that the function will not alter student values
	{
		cout << "Student ID: " << sid << "\t";
		cout << "Name: " << sname << "\t";
		for (int i = 0; i < NUM_SCORES; i++)
			cout << score[i] << "\t";
		cout << endl;
	}
};


class StudentCompare //compares students based on summation of scores
{
public:
    int operator()(const Students &lhs, const Students &rhs) //Operator Overloading (overloading the parentheses)
    {
        double lhsSum = 0.0, rhsSum = 0.0; //declares two doubles, each with value 0.0
        vector<double> score; //declares a vector of doubles
        score = lhs.getScore(); // the score vector is assigned the score values of the left hand side argument of the () operator
        for(int i=0; i<score.size(); i++)
            lhsSum += score[i]; // for loop iterates through this vector and adds each value to lhsSum
        score = rhs.getScore(); // score is REASSIGNED to the score values of the right hand side argument of the () operator
        for(int i = 0; i < score.size(); i++)
            rhsSum += score[i];
        return lhsSum < rhsSum; // Prioritizes scores in descending order

    }
};

class StudentIDCompare //compares students based on ID
{
public:
    int operator()(const Students &lhs, const Students &rhs) //Operator Overloading (overloading the parentheses)
    {
        return lhs.getSid() > rhs.getSid(); //Prioritizes IDs in ascending order
    }
};

class StudentNameCompare //compares students based on alphabetical order of name
{
public:
    int operator()(const Students &lhs, const Students &rhs)
    {
        return lhs.getSname() < rhs.getSname();
    }
};



int main()
{
	Students s1, s2, s3; //declare three objects of the Students type
	Students pop_student; //declare another object of the Students type

	//assign values to the various attributes of each Students object

	s1.setSid(10000001);
	s1.setSname("Bill");
	s1.setScore(100, 100, 100);
	s1.printStudent();

	s2.setSid(10000002);
	s2.setSname("Kurt");
	s2.setScore(100, 90, 100);
	s2.printStudent();

	s3.setSid(10000003);
	s3.setSname("Greg");
	s3.setScore(100, 90, 50);
	s3.printStudent();

	priority_queue<Students, vector<Students>, StudentNameCompare> pq; //create a priority queue which sorts students based on the first letter of their name
	// this priority queue is made of a vector of the Students data type, and uses a custom class to prioritize based on our own goals

	pq.push(s1); //push students to the priority queue, which are automatically sorted
	pq.push(s2);
	pq.push(s3);

    while(!pq.empty())
    {
        pop_student = pq.top(); //assigns the student at front of queue to the pop_student variable
        pop_student.printStudent(); //outputs the information for this student using the printStudent() function
        pq.pop(); //deletes the student at the front of the queue
    }


}
