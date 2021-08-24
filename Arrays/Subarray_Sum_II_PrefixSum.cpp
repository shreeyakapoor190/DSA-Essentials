#include <iostream>
using namespace std;
// PREFIX SUMS      O(N^2)
// this method is used to reduce the time complexity of Brute force method O(N^3) to O(N^2)
// prefix array will store the cumulative sum of all the elements upto that element
// buliding prefix sum array takes O(N)
// we calculate the sum of the subarray using prefix_sum[j]-prefix_sum[i-1] where i is the start of the subarray
// and j is the end of subarray
// Here, we get the sum of subarray in constant time and no new loop is req.
void largestSubarraySum(int arr[], int n)
{
    // prefix sum
    int prefix[n] = {0};
    int subArraySum, i, j, largestSum = 0;
    prefix[0] = arr[0];
    for (i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    // largest sum logic
    for (i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i > 0)
                subArraySum = prefix[j] - prefix[i - 1];
            else
                subArraySum = prefix[j];
            largestSum = max(largestSum, subArraySum);
        }
    }
    cout << largestSum;
}

int main()
{
    int arr[] = {1, 2, -3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << "largest subarray sum: " << endl;
    largestSubarraySum(arr, n);
    return 0;
}