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

int main()
{
	const int N = 10;
	Students *ptr;

	ptr = makeStudents(N);
	printStudents(ptr, N);

	fstream f;
	f.open("students.bin", ios::out | ios::binary);

	if (f.is_open())
    {
		for ( int i =0; i<N; i++) {
			f.write((char *)(ptr+i), sizeof(Students));
			cout << (ptr+i)->sid << endl;
			cout << (ptr+i)->sname << endl;
			cout << (ptr+i)->scores[0] << endl;
			cout << (ptr+i)->total_score << endl;

		}
        // f.write(reinterpret_cast<char*>(ptr), N * sizeof(Students));

        f.close();
    }
    else{
        cout << "Error opening binary file.\n" << endl;
    }


}

Students *makeStudents(int N)
{

    Students    *ptr= new Students [N];
    ifstream ifs;
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
