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
    Node *res = curr, *r, *s = res;
    while (curr)
    {
        r = curr->prev;
        res->prev = curr->next;
        res->next = r;
        curr = curr->next;
        res = res->next;
    }
    return s;
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
}