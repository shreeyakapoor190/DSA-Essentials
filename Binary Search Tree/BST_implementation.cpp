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

Node *insert(Node *root, int x)
{
    if (!root)
        return new Node(x);
    // rescursive case
    if (root->key > x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void printInorder(Node *root) // inorder print will always sort the elements in ascending order
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->key << "  ";
    printInorder(root->right);
    cout << endl;
}
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
Node *findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root; // leftmost node return krega and that will be the smallest
}
Node *remove(Node *root, int target)
{
    if (!root)
        return NULL;
    // first we will search for the target node
    if (root->key > target)
        root->left = remove(root->left, target);
    else if (root->key < target)
        root->right = remove(root->right, target);
    else
    {
        // when the current node matches with target
        // CASE 1: NO CHILDREN
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        // CASE 2: 1 CHILD
        else if (!root->left && root->right)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->left && !root->right)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // CASE 3: 2 CHILDREN
        else
        {
            Node *temp = findMin(root->right);
            root->key = temp->key;                        /// copying the value of that node into current root node
            root->right = remove(root->right, temp->key); // to delete the temp wla key from
            // the right subtree where it was originally present
        }
        return root;
    }
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    Node *root1 = NULL;
    int arr[] = {4, 5, 7, 12, 8, 10};
    for (int x : arr)
    {
        root1 = insert(root1, x);
    }
    cout << search(root, 40) << endl;
    printInorder(root1);
    root1 = remove(root1, 7);
    printInorder(root1);
}
