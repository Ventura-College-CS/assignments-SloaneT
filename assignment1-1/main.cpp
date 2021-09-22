#include <iostream>
#include <fstream>

using namespace std;


struct Student {
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

void printStudent(Student s);

int main()
{
    ifstream ifs;
    ofstream ofs;

    Student s[10];

    ifs.open("students.txt");
    ofs.open("students.bin");

	if (ifs.fail() )
	{
		cout << " Could not open the file \n";
		exit(0);
	}

	for(int i=0; i<10; i++)
	{
		ifs >> s[i].id ;
		ifs >> s[i].sname ;
		ifs >> s[i].score[0] ;
		ifs >> s[i].score[1] ;
		s[i].sum = s[i].score[0] + s[i].score[1];
		s[i].avg = s[i].sum / 2.0;
		printStudent(s[i]);
		ofs.write( (char *)&s[i], sizeof(s[i]) );
	}

}

void printStudent(Student s)
{
	cout << s.id << "\t" ;
	cout << s.sname << "\t";
	cout << s.score[0] << " " << s.score[1] << "\t";
	cout << s.sum << " " << s.avg << endl;
}




