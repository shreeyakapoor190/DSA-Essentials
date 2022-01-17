#include <iostream>
#include <deque>
// deque can function as both stack and queue
// it is a doubly ended queue
using namespace std;
int main()
{
    deque<int> dq = {10, 20, 30}; // initialization of deque 10 20 30
    dq.push_front(5);             // 5 10 20 30
    dq.push_back(50);             // 5 10 20 30 50
    for (auto x : dq)
        cout << x << "  ";
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_back();     // 5 10 20 30
    dq.pop_front();    // 10 20 30
    cout << dq.size(); // 3
    return 0;
}