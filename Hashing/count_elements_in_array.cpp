// counting the no of elements in an array using key value pair in unordered map
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {10, 20, 10, 20, 40, 50, 60};
    unordered_map<int, int> h;
    for (auto x : arr)
        h[x]++;
    for (auto e : h)
        cout << e.first << " " << e.second << endl;
}