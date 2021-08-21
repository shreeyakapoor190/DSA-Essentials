#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    // passing arrays in a function takes place by pass by reference method
    // therefore we need to pass the size of the array along with the arr[] as argument in the function
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    return 0;
}