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
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
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
void levelOrderLinebyLine(Node *root) // more used while solving questions
{
    // after every level insert a NULL which will specify the end of one level and start of new level
    // When we take out a null from the queue, it means that we have reached the end of the current level.
    // So we now have a new level completely inside the queue and we again push null into the queue to indicate this.
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
int diameter(Node *root) // time complexity O(N^2)- at every node we are calculating the height of tree
{
    if (!root)
        return 0;
    // get height of left and right subtree
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currHeight = lHeight + rHeight + 1; // when diameter passes through the root/curr node
    // therefore left subtree+ right subtree+ the node itself

    // get diameter of left and right subtree
    int lDiameter = diameter(root->left);  // when diameter lies in the left subtree
    int rDiameter = diameter(root->right); // when diameter lies in the right subtree

    return max(currHeight, max(lDiameter, rDiameter));
}
int diameterOptimized(Node *root) // time complexity O(N)
{
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
    cout << endl;
    cout << "level order line by line: \n";
    levelOrderLinebyLine(root);
    cout << endl;
    cout << "diameter of tree: " << diameter(root) << endl;
    cout << "diameter of tree: " << diameterOptimized(root) << endl;
}