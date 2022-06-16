#include <iostream>
#include <vector>
using namespace std;
void findSubsets(char *input, char *output, int i, int j)
{
    // base case
    // base case is when we reach the end of the string and input is NULL
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    // recursive case
    // 2 options available-
    // include the i th letter
    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1);
    // exclude the i th letter
    findSubsets(input, output, i + 1, j); // we will not update j here so that even if we add a character
                                          // in the output array, it will later get replaced since the index
                                          // has not been increased and this call will overwrite the command
                                          // executed at line 17
}
int main()
{
    char input[100];
    char output[100];
    cin >> input;
    findSubsets(input, output, 0, 0);
    return 0;
}