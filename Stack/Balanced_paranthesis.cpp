// no of opening brackets and the corresponding closing brackets must be same
// last opened bracket must be closed first
#include <iostream>
#include <stack> // import stack class to use it
using namespace std;
bool isBalanced(string str)
{
    stack<int> s;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(') // all opening bracket gets pushed in stack
            s.push(str[i]);
        else
        {
            if (s.empty()) // when there's no opening bracket and only closing bracket
                return false;
            else if ((s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']') || (s.top() == '{' && str[i] == '}') == false)
                return false;
            else
                s.pop();
        }
    }
    return (s.empty() == true); // extra opening bracket
}
int main()
{
    string str;
    cout << "Enter a string:\t";
    cin >> str;
    cout << isBalanced(str);
}