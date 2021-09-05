#include <iostream>
#include <vector>
using namespace std;
// COUNTING SORT
// TIME COMPLEXITY - O(linear+range) = O(n+k) linear complexity

void countingSort(int arr[], int n)
{
    // finding laregst element which is the range of the array
    int largest = -1; //considering the array has all positive elements
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }
    // creating a count array
    // int *freq = new int[largest + 1]; //created a dynamic array coz we dont know the size of the range
    vector<int> freq(largest + 1, 0); //vector is a dynamic array therefore we can use that as well
    // largest+1 denotes the size of vector
    // 0 denotes that we are initialising the vector with 0

    // update the freq array
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++; //increasing the count of that number
    }

    // put back the elements from the freq array into the original array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i; //putting the element in original array
            freq[i]--;  //decreasing the count in the freq array until it becomes zero
            j++;        //increasing the pointer in the original array
        }
    }
    return;
}
int main()
{
    int arr[] = {1, 76, 43, 56, 23, 90};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}