// All the elements of the array are scanned until we get the searched value
// The seaech is done in a loop either starting from 1st index or last
// it returns -1(say) if element is not present
// LINEAR SEARCH HAS A COMPLEXITY OF O(N).
// where n is the size of the array . Therefore time taken is proportional to the size of the array.
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        //if current element matches with the key
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cout << "Enter key: ";
    cin >> key;
    int index = linearSearch(arr, n, key);
    if (index != -1)
        cout << key << " is present at index " << index;
    else
        cout << key << " not found!";
    return 0;
}