#include <iostream>
using namespace std;
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
void printList(Node *head) // circular linked list traversal using FOR LOOP
{
    if (head == NULL) // for no node linked list
        return;
    cout << head->data << "   "; // print the 1st node coz the condition for the loop is that current pointer != head
    // therefore print the head node separately
    for (Node *p = head->next; p != head; p = p->next) // took a separate pointer and initialised with next of head
        cout << p->data << "    ";
    cout << endl;
    // in case of a single node circular linked list, we will never enter the for loop
    // at first the node data is printed of the 1st node
    // then when we initialize the p pointer as head->next, which here will be the head itself
    // coz the next of last node= head node , therefore condition becomes false and it never enters the for loop
}
void printList2(Node *head) // circular linked list traversal using do-while loop
{
    if (head == NULL) // for no node linked list
        return;
    Node *p = head;
    do
    {
        cout << p->data << "    ";
        p = p->next;
    } while (p != head);
    cout << endl;
    // do-while loop method for traversal is better than the for loop method
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // making the next of last node as head to make a circular loop
    cout << "Circular linked list is: ";
    printList(head); // using for loop
    cout << "Circular linked list is: ";
    printList2(head); // using do-while loop
}
