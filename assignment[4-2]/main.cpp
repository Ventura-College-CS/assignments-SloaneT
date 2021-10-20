#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(int array[], int, int);
int linearSearch(int [], int, int);
void makeArray(int array[], int);
void bubbleSort(int array[], int);
void printArray(int array[], int);
int compareBinarySearch(int [], int, int);
int compareLinearSearch(int [], int, int);


int main()
{
    const int N = 1024; // 2**7
    const int TRIES = 1000;
    int array[N];
    int target, foundindex;
    int compNumber;

    srand(time(0));
    makeArray(array, N);
    bubbleSort(array, N);
    printArray(array, N);

    compareLinearSearch(array, N, target);
    compareBinarySearch(array, N, target); // After converting to separate function, returns average of 9 comparisons instead of 8

    }

int linearSearch(int array[], int N, int target)
{
    int comp;
    for (int i = 0; i < N; i++){
        comp++;
        if (array[i] == target){
            return comp;
        }
    }
    return comp;
}

int compareLinearSearch(int array[], int N, int target)
{
    const int TRIES = 1000;
    int compNumber;
        for(int trynumber = 0; trynumber<TRIES; trynumber++)
        {
        target = array[rand() % N ]; // 0 to 1023
        compNumber += linearSearch(array, N, target);
        cout << "Comparisons executed: " << compNumber << endl;
        }
        cout << "Average comparison number " << compNumber / TRIES << endl;
}

int compareBinarySearch(int array[], int N, int target)
{
    const int TRIES = 1000;
    int compNumber;
    for(int trynumber = 0; trynumber<TRIES; trynumber++)
        {
        target = array[rand() % N ]; // 0 to 1023
        compNumber += binarySearch(array, N, target);
        cout << "Comparisons executed: " << compNumber << endl;
        }
        cout << "Average comparison number " << compNumber / TRIES << endl;
}

int binarySearch(int array[], int N, int target)
{
 int first, last, mid, comp;

    first = comp = 0;
    last = N - 1;

    while(first <= last)
    {
        mid = (first + last) / 2;
        comp++;

        if (target == array[mid])
        {
			return comp;
            // cout << "Found " << target << " after " << comp << " comparisons\n";
            // break;
        }
        else if (target < array[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return comp;
}

void bubbleSort(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}



void makeArray(int array[], int N)
{
    for(int i = 0; i <N; i++)
        array[i] = rand() % 1000 + 1;
}

void printArray(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
        if (i % 8 == 7)
            cout << endl;
    }
}


