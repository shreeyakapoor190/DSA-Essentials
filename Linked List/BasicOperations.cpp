#include <iostream>
using namespace std;
// LINKED LIST - memory created dynamically
// head node stores the add of 1st node
// head node does not store any data (only the add of 1st node)
// data type of head = node*
// 1st node has 2 parts = data of the node + add of 2nd node
// all the nodes are of the data type defined by us - custom datatype - node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "   ";
        head = head->next;
    }
    cout << endl;
}
// recursive display of linked list
void rPrint(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    rPrint(head->next);
}
// insertion at beginning of linked list
Node *insertBegin(Node *head, int x) //O(1) time complexity
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp; //here we are returning the new head of the list, therefore while calling
    // from main function, the head must get updated and hence here it is stored in head variable
    // to update it
}
// insertion at the end of the list
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}
// delete the first node of linked list
Node *delHead(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}
Node *delTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next->next;
        temp->next = NULL;
        return head;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head); //traversing and printing linked list
    rPrint(head);    //recursive traversal in linked list
    cout << endl;
    cout << "insert at begin:   ";
    head = insertBegin(head, 40); //insertion of 40 at beginning of linked list
    printList(head);
    cout << "insert at end:     ";
    head = insertEnd(head, 50); //inserted 50 at end of linked list
    printList(head);
    cout << "delete head node:      ";
    head = delHead(head);
    printList(head);
    cout << "delete tail node:     ";
    head = delTail(head);
    printList(head);
    return 0;
}