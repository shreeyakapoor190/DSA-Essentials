#include <iostream>
using namespace std;
// KADANE'S ALGORITHM
// works in linear time
// we take current_sum and max_sum
// If the current sum at any point is negative convery it into 0 and ignore that
int maximumSubarraySum(int arr[], int n)
{
    int i, curSum = 0, maxSum = 0;
    for (i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum < 0)
            curSum = 0;
        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}
int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << maximumSubarraySum(arr, n);
    return 0;
}