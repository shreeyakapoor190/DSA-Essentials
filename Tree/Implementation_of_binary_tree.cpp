// binary tree can have at-most 2 children
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
    return;
}
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}
void levelOrder(Node *root)
{
    // Enque a level into the queue
    //  then take out these items from the queue and print and while taking
    // out the items we enque the children of these node i.e. the next level is enqued
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    cout << "inorder traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "preorder traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "postorder traversal" << endl;
    postorder(root);
    cout << endl;
    cout << "height of the tree is: " << height(root) << endl;
    cout << "level order traversal/ breadth first search: " << endl;
    levelOrder(root);
}