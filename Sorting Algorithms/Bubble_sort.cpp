#include <iostream>
using namespace std;
// SORTING: arranging data in either increasing or decreasing order.
// TAKE LARGER ELEMEMT TO THE END BY REPEATEDLY SWAPPING THE ADJACENT ELEMENTS
//we will compare the adjacent elements each time and swap in a way the elements accordingly
// a[j] and a[j+1] are compared each time
// TIME COMPLEXITY -O(N^2)
int bubbleSort(int arr[], int n)
{
    // sorting in increasing order
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // repeated swapping
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
int main()
{
    int arr[] = {-13, -17, -8, -10, -20, 2, 3, -19, 2, -18, -5, 7, -12, 18, -17, 12, -1};
    int n = sizeof(arr) / sizeof(int);
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "after sorting:" << endl;
    bubbleSort(arr, n);
    return 0;
}
