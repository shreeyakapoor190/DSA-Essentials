// fibonacci using dynamic programming
#include <iostream>
using namespace std;
int main()
{
    int i, n;
    cin >> n;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n];
    return 0;
}