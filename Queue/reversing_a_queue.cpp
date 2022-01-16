#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// to reverse a queue in iterative method, we will first empty the queue and push the elements in stack
// and then empty the stack and push it back into the queue
// hence the stack will reverse the elements of the queue
void reverse(queue<int> &q)
{

    stack<int> rev;
    while (q.empty() == false)
    {

        rev.push(q.front());
        q.pop();
    }
    cout << rev.size();
    while (rev.empty() == false)
    {
        q.push(rev.top());
        rev.pop();
    }

    return;
}
int main()
{
    queue<int> q;
    q.push(10); // 10
    q.push(20); // 10 120
    q.push(30);
    // queue traversal
    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }
    reverse(q);
}