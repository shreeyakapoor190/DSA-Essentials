// printing all the possible pair of elements inside an array
#include <iostream>
using namespace std;
void printingPairs(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            cout << "[" << arr[i] << "," << arr[j] << "]    ";
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    //printing all values of array
    for (int x : arr)
    {
        cout << x << endl;
    }
    printingPairs(arr, n);
    return 0;
}
