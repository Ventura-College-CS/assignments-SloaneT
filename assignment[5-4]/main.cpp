#include <iostream>
#include "VectorQueue.h"
#include <vector>
using namespace std;

struct Student {
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};


int main()
{
    VectorQueue<int, 10> arrayQueue;
    VectorQueue<Student, 10> studentQueue; //how to fill parameters for enqueue?
    return 0;
}
