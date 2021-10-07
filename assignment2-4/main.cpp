#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
	double  total_score;
};

Students *makeStudents(int);
void printStudents(Students * const, int);
void sortStudents(Students * const, int);
void changeStudentValue(Students *i, Students *j);


int main()
{
	const int N = 10;
	Students *ptr;

	ptr = makeStudents(N);
	printStudents(ptr, N);
	sortStudents(ptr, N);
	printStudents(ptr, N);


}

Students *makeStudents(int N)
{
	ifstream ifs;
    Students    *ptr= new Students [N];

    ifs.open("students.txt");
    if ( ifs.fail())
    {
        cerr << "File open error\n";
        exit(0);
    }

	for(int i=0;i<N; i++)
    {
        ifs >> (ptr+i)->sid >> (ptr+i)->sname;
        for(int j=0; j<NUM_SCORES; j++)
			ifs >> (ptr+i)->scores[j] ;

		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
    }
	return ptr;
}

void printStudents(Students * const ptr, int N)
{
    double temp_total;
for(int i=0; i < N; i++)
	{
		cout << "ID: " << (ptr+i)->sid << endl;
		cout << "Name: " << (ptr+i)->sname << endl;
		cout << "Scores: " << endl;
		for(int j = 0; j < NUM_SCORES; j++){
            cout << (ptr+i)->scores[j] << endl;
            temp_total += (ptr+i)->scores[j];
		}
            cout << "Total Score: " << endl;
            cout << temp_total << endl;
            (ptr+i)->total_score = temp_total;
            temp_total = 0;
            cout << endl;
	}
}


void sortStudents(Students * const ptr, int N)
{
    for(int i = 0; i < N-1; i++)
        {
        for (int j = i+1; j < N ; j++)
        {
            // int temp;
			Students tmp1, tmp2;
			tmp1 = tmp2;

            if ((ptr+i)->total_score > (ptr+j)->total_score)
            {
                changeStudentValue(ptr+i, ptr+j);
            }
        }
    }
}

void changeStudentValue(Students *i, Students *j)
{
    Students temp = *i;
    *i = *j;
    *j = temp;
    /*
	int tmp;
	tmp = i->sid;
	i->sid = j->sid;
	j->sid = tmp;

    swap((i->sname), (j->sname));

	swap(i->scores, j->scores);

	double tmp4;
	tmp4 = i->total_score;
	i->total_score = j->total_score;
	j->total_score = tmp4;
	*/


}
