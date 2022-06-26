#include <iostream>
using namespace std;

// printing my name n times with recursion
void name(int n)
{
    if (n == 0)
        return;
    cout << "Shreeya Kapoor\n";
    name(n - 1);
}
int main()
{
    name(2);
}