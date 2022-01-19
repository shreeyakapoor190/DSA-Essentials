// unordered set is based on hashing and is used to store keys
// the order in which the elements are stored is based on hashing and not in the order in which we insert
// ṭhe values
// used to perform operations like insert, search and delete on keys.
#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(10); // insert function is used to insert values into unordered set
    s.insert(5);
    s.insert(15);
    s.insert(20);
    // traversal in unordered set
    for (int x : s)
    {
        cout << x << " "; // order might not necessarily be 10 5 15 20
    }
    cout << endl;
    // traversal in unordered set
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    if (s.find(15) == s.end()) // if the find iterator reaches the end of the unodered set it means element not found
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }

    // count() is also used to find if an element is present or not
    if (s.count(5))
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    // erase() is used to erase an element or a range of elements
    s.erase(15);          // 2 ways of erasing either by directly passing the element
    auto it = s.find(10); // method 2 of erasing:finding the iterator which points to the element
    s.erase(it);          // then passing the iterator which points to the element in erase function
    cout << s.size() << endl;
    s.clear(); // clears the entire unordered set
    cout << s.size();
    return 0;
}