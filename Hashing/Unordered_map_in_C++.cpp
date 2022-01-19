// Unordered map is used to store key value pairs using hashing
// there is no particular order of keys
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m["gfg"] = 20;
    m["ide"] = 30;
    m.insert({"courses", 15});
    // traversal through the unordered map
    for (auto x : m)
        cout << x.first << " " << x.second << endl; // order in which elements are printed is random and does not depend on the order of insertion

    // iterating through the unordered map
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (it->first) << " " << it->second << endl; // since it is a pointer therefore we use arrow to access the first and second of the map here instead of dot operator
    }
    if (m.find("ide") != m.end()) // find does not point to the end operator i.e element is present in map
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    // count() is also used to find if an element is present or not in the map
    if (m.count("ide") > 0)
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    // size() returns the number of key value pairs in the unordered map
    cout << m.size() << endl;
    m.erase("ide");
    m.erase(m.begin()); // removes 1st element: here we have passed iterator to the erase function
    cout << m.size() << endl;
}