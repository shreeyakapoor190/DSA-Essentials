#include <iostream>
#include <vector>
using namespace std;
// dynamically resizable stack
struct MyStack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int res = v.back(); // to store the top element [back returns the last item of vector]
        v.pop_back();
        return res;
    }
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty(); // vector function empty is used
    }
    int peek()
    {
        return v.back();
    }
};
int main()
{
    MyStack s;
    s.push(5);                   // 5
    s.push(10);                  // 5 10
    s.push(20);                  // 5 10 20
    cout << s.pop() << endl;     // 5 10
    cout << s.peek() << endl;    // 10
    cout << s.isEmpty() << endl; // false
    return 0;
}
