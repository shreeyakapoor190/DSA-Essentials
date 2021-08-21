#include <iostream>
using namespace std;
int main()
{
    int marks[100];
    int n;
    cout << "Enter no of students: ";
    cin >> n;
    // assign a value
    marks[0] = 2;
    //input of array elements
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
        // updation
        marks[i] *= 2;
    }
    //output of array elements
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << endl;
    }
    // the array elements which have no value assigned will have garbage value
    // But if we do the initialization of some values the remaining values will become 0 themselves
    // for that we will define in this from -int marks[100]={1};
}