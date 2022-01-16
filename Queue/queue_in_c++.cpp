#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);                // 10
    q.push(20);                // 10 120
    q.push(30);                // 10 20 30
    cout << q.front() << endl; // 10
    cout << q.back() << endl;  // 30

    q.pop();                   // 20 30
    cout << q.front() << endl; // 20
    cout << q.back() << endl;  // 30
    cout << q.size() << endl;
    // queue traversal
    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }
}
// basic operations are - push, pop, front, back, size, empty