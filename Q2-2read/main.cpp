#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
	double  total_score;
};

// void printStudents(Students * const, int);
void printStudents(Students * const);

int main()
{
	const int N = 10;

	fstream f;
	Students *sptr = new Students [N];

    f.open("students.bin", ios::in | ios::binary);

	if (f.is_open())
    {
		for ( int i =0; i<N; i++) {
			f.read((char *)(sptr+i), sizeof(Students));
			if (f.bad())
			{
				cerr << "Reading Error\n";
				exit(0);
			}
		}
        f.close();
    }
    else{
        cout << "Error opening binary file.\n" << endl;
    }


    cout << sizeof(sptr);



    for (int i = 0; i < N; i++)
    {
		if(((sptr+i)->total_score)/3 >= 50){
			printStudents(sptr+i);
		}
    }


	//printStudents(ptr, N);



}



void printStudents(Students * const ptr)
{
    double temp_total;
		cout << "ID: " << (ptr)->sid << endl;
		cout << "Name: " << (ptr)->sname << endl;
		cout << "Scores: " << endl;
		for(int j = 0; j < NUM_SCORES; j++){
            cout << (ptr)->scores[j] << endl;
            temp_total += (ptr)->scores[j];
		}
            cout << "Total Score: " << endl;
            cout << temp_total << endl;
            (ptr)->total_score = temp_total;
            temp_total = 0;
            cout << endl;
}






