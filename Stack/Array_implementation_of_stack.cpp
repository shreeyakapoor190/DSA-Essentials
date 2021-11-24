#include <iostream>
using namespace std;
// we can use vector to create a dynamic sized stack
struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int c) // constructor which takes capacity as input
    {
        cap = c;
        arr = new int[cap]; // dynamically allocate memory
        top = -1;
    }
    void push(int x) // time complexity = O(1)
    {
        if (top == cap - 1) // handle boundary conditions when stack is already full
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop() // time complexity = O(1)
    {
        if (top == -1) // handle boundary condition of underflow
        {
            cout << "empty stack" << endl;
            return -1225454; // return some garbage value
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if (top == -1) // handle boundary condition of underflow
        {
            cout << "empty stack" << endl;
            return -11515123; // return some garbage value
        }
        return arr[top];
    }
    int size()
    {
        return top + 1; // index starts from 0 therefore size will be index+1
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};
int main()
{
    MyStack s(5);
    cout << s.pop() << endl; // to check boundary conditions
    cout << s.peek() << endl;
    s.push(5);                   // 5
    s.push(10);                  // 5 10
    s.push(20);                  // 5 10 20
    cout << s.pop() << endl;     // 5 10
    cout << s.peek() << endl;    // 10
    cout << s.isEmpty() << endl; // false
    return 0;
}