#include <iostream>
using namespace std;
// printing all the subarrays of a given array
// SUBARRAY : smaller continuous part of a given array
// subarray can start and end at any position in the array (start<end always)
// NUMBER OF SUBARRAYS : proportional to n^2 , n= no of elements
// TIME COMPLEXITY : O(n*n*n) = O(n^3)
// BRUTE FORCE APPROACH O(N^3)
void printingSubarrays(int arr[], int n)
{
    int i, j, k;
    int max = 0, sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            sum = 0;
            for (k = i; k <= j; k++)
            {
                cout << arr[k] << ",";
                sum += arr[k]; //sum of each subarray
            }
            cout << endl;
            cout << "sum of subarray" << sum << endl;
            if (sum > max)
                max = sum; //finding the subarray with largest sum
        }
    }
    cout << "sum of largest subarray: " << max << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << "Subarrays are: " << endl;
    printingSubarrays(arr, n);
    return 0;
}