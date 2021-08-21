// Binary search works on a sorted array
// Search space is mono-tonic [non-decreasing or non- increasing]
// the given array is sorted either in ascending or descending order
//  At each step , WE WILL DIVIDE THE ARRAY INTO TWO PARTS , EVERYTIME BY THE MIDDLE ELEMENT

// start=0      end=n-1
// while (start<end){

// find midpoint;
// do comparision at midpoint;
//  start = mid + 1 :everytime the value searched is greater than the current midpoint
//  end = mid - 1: everytime the value searched is less than the current midpoint

// }
//start>end : element not present and the entire array has been scanned

// TIME COMPLEXITY : O(log(n)) where n is the size of array
// coz each time the size of array gets reduced/divided by 2
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 3, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cout << "enter key: ";
    cin >> key;
    int index = binarySearch(arr, n, key);
    if (index != -1)
        cout << key << " present at " << index;
    else
        cout << key << " not present." << endl;
    return 0;
}