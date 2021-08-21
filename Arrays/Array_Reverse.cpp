// Effective method:
// take start of array and end of array
// iterate upto the midpoint of the array
// keep swapping the start and the end elements until midpoint is reached
// Will work for even as well as odd number of elements

// TIME COMPLEXITY : O(n) where n is the no of elements
// SPACE COMPLEXITY : O(1)
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int s = 0, e = n - 1, x;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        // x = arr[s];
        // arr[s] = arr[e];
        // arr[e] = x;
        swap(arr[s], arr[e]); //swap() is an inbuilt function in C++ to swap to value at 2 storage locations
        s++;
        e--;
    }
}
int main()
{
    int i;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    reverseArray(arr, n);
    cout << endl;
    cout << "reversed array: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}