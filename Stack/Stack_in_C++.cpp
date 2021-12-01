#include <iostream>
#include <stack> // import stack class to use it
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);               // 10
    s.push(20);               // 10 20
    s.push(30);               // 10 20 30
    cout << s.size() << endl; // 3
    cout << s.top() << endl;  // 30
    s.pop();
    cout << s.top() << endl; // 20
    // STACK TRAVERSAL:
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}