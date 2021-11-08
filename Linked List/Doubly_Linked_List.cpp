#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << "   ";
        head = head->next;
    }
    cout << endl;
}
Node *insertAtBegin(Node *head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    return n;
}
Node *insertAtEnd(Node *head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
        return n;
    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = n;
    n->prev = curr;
    return head;
}
Node *revere(Node *head)
{
    Node *curr = head;
    Node *res = new Node(0);
    while (curr->next)
    {
        if (head == NULL || head->next == NULL) // blank linked list or single node case
            return head;
        Node *prev = NULL, *curr = head;
        while (curr)
        {
            prev = curr->prev;       // prev is temporary variable used for swapping
            curr->prev = curr->next; // swapping
            curr->next = prev;       // swapping
            curr = curr->prev;       // move curr backward coz curr's next has already been reversed
        }
        return prev->prev; // in 5 10 20 30 50, 30's prev will be 50 now, so returned 50 as the new head
    }
    return head;
}
Node *delHead(Node *head)
{
    // time complexity = theta(1)
    if (head == NULL) //  no node case
        return NULL;
    if (head->next == NULL) // single node case
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    cout << "Doubly Linked list: ";
    printList(head);
    cout << "Insertion at beginning:  ";
    head = insertAtBegin(head, 5); // inserting 5 at the beginning of linked list
    printList(head);
    cout << "Insertion at end:  ";
    head = insertAtEnd(head, 50); // inserting 50 at the end of linked list
    printList(head);
    cout << "reverse a doubly linked list:    ";
    head = revere(head);
    printList(head);
    cout << "delete head of a doubly linked list:    ";
    head = delHead(head);
    printList(head);
}