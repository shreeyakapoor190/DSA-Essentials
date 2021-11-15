#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPlaindrome(int n)
{
    int d, rev = 0, num = n;
    while (n != 0)
    {
        d = n % 10;
        rev = rev * 10 + d;
        n /= 10;
    }
    return (rev == num);
}
int main()
{
    int n = 123321;
    cout << "no is palindrome?    " << isPlaindrome(n) << endl;
    return 0;
}