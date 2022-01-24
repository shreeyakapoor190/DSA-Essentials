#include <iostream>
using namespace std;
// inbuilt function to convery a binary number to decimal
int main()
{
    char binaryNumber[] = "1001";
    cout << stoi(binaryNumber, 0, 2);
    return 0;
}
