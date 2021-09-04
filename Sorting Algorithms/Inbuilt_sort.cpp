#include <iostream>
#include <algorithm>
using namespace std;

// the inbulit sort() function of cpp works with TIME COMPLEXITY - O(N logN)
// the arguments passed - starting point of array from where we need to sort , end of the array(till where we have to sort)
int main()
{
    int arr[] = {-1, 5, 78, -96, 84, 21, 63};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n); //the start and ending point of sort
    // printing the sorted array in ascending order
    for (int x : arr)
    {
        cout << x << "    ";
    }
    cout << endl;
    reverse(arr, arr + n); //TO SORT IN DESCENDING ORDER - SORT IN ASCENDING ORDER FIRST THEN REVERSE
    // THE ENTIRE ARRAY
    // Printing in descending order
    for (int x : arr)
    {
        cout << x << "    ";
    }
    cout << endl;
    // other method of sorting in descending order is
    sort(arr, arr + n, greater<int>());
    for (int x : arr)
    {
        cout << x << "    ";
    }
}