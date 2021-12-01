// Recursive Binary Search
// This program borrows heavily from https://www.geeksforgeeks.org/binary-search/
#include <iostream>
using namespace std;


//accepts a sorted array arr[l..r] and returns location of target if present, else -1
int binarySearch(int arr[], int l, int r, int target)
{
    if (r >= l) {
        int mid = l + (r - l) / 2; // mid = leftmost index + (rightmost - 1) / 2

        // If the element is present at the middle
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, then
        // it can only be present in left sub-array
        if (target < arr[mid])
            return binarySearch(arr, l, mid - 1, target); //replaces r with mid-1

        // Else the element can only be present
        // in right sub-array
        return binarySearch(arr, mid + 1, r, target); //replaces l with mid+1
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int target = 10;
    //divide the size in bytes of entire array
    //by the size in bytes of one element to find array length
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, target);
        if (result == -1)
        {
          cout << "Element is not present in array";
        }
        else
        {
            cout << "Element is present at index " << result << endl;
        }
    return 0;
}
