#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countDigits1(int n) // iterative solution - time complexity = theta(d), d id no of digits
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}
int countDigits2(int n) // recursive solution
{
    if (n == 0)
        return 0;
    return 1 + countDigits2(n / 10);
}
int countDigits3(int n) // logarithmic solution
{
    return floor(log10(n) + 1); // log returns 2.08+1=3.08 's floor =3
}
int main()
{
    int n = 123;
    cout << "digits in number" << countDigits1(n) << endl;
    cout << "digits in number" << countDigits2(n) << endl;
    cout << "digits in number" << countDigits3(n) << endl;
    return 0;
}