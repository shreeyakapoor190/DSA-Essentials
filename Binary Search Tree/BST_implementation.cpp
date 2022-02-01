#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
bool search(Node *root, int x)
{
    if (root == NULL) // base case when the root passes is null or when we reach the leaf node
        return false;
    else if (root->key == x)
        return true;
    else if (root->key > x)
        return (search(root->left, x));
    else
        return (search(root->right, x));
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    cout << search(root, 40);
}
