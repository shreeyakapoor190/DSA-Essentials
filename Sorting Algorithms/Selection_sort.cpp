#include <iostream>
using namespace std;
// SELECTION SORT:
// Repeatedly finding the minimum element from the unsorted part of the array and
// putting it at the beginning of the array
void selectionSort(int arr[], int n)
{
    for (int pos = 0; pos <= n - 2; pos++)
    {
        int current = arr[pos];
        int min_position = pos;
        for (int j = pos; j < n; j++)
        {
            if (arr[j] < arr[min_position])
            {
                min_position = j;
            }
        }
        swap(arr[min_position], arr[pos]);
    }
}
int main()
{
    int arr[] = {1, 4, 3, 7, -10};
    int n = sizeof(arr) / sizeof(int);
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}