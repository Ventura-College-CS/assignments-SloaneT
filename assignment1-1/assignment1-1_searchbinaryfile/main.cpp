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
void findStudent(Student s[], int target_id);

int main()
{
    ifstream ifs;
    Student s[10];
	int target_id;

	ifs.open("students.bin");

	if ( ifs.fail() )
	{
		cout << " Could not open the file \n";
		exit(0);
	}

	for(int i=0; i<10; i++){
		ifs.read( (char *)&s[i], sizeof(s));
		printStudent(s[i]);
	}

	cout << "Please enter the Student ID for which you wish to retrieve information : ";
	cin >> target_id;
	findStudent(s, target_id);

	ifs.close();
}

void findStudent(Student s[], int target)
{
	int found=0;
	for( int i=0;i<10; i++){
		if ( s[i].id == target){
			printStudent(s[i]);
			found = 1;
		}
	}
	if(!found)
		cout << "The ID " << target << " was not found\n";
}

void printStudent(Student s)
{
	cout << s.id << "\t" ;
	cout << s.sname << "\t";
	cout << s.score[0] << " " << s.score[1] << "\t";
	cout << s.sum << " " << s.avg << endl;
}
