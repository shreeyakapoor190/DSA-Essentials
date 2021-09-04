// INSERTION SORT
// Time Complexity: O(n^2)
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int i, j, current, prev;
    for (i = 1; i <= n - 1; i++)
    {
        current = arr[i];
        prev = i - 1;
        // loop to find the right index where the element should be inserted
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev]; //shifting element to the right bcoz it is greater than the current element
            prev = prev - 1;           //decreasing value of previous to compare with the next element in sorted part
        }
        arr[prev + 1] = current;
    }
}
int main()
{
    int arr[] = {5, 4, 1, 3, 2, -10};
    int n = sizeof(arr) / sizeof(int);
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "after sorting: ";
    insertionSort(arr, n);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}