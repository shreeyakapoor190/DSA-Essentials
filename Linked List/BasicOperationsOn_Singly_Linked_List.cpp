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
Node *insertBegin(Node *head, int x) // O(1) time complexity
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp; // here we are returning the new head of the list, therefore while calling
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
Node *insertAtPosition(Node *head, int pos, int data)
{
    Node *curr = head;
    int len = 1;
    // inserting in beginning
    if (pos == 1)
    {
        Node *in = new Node(data);
        in->next = curr;
        head = in;
        return head;
    }
    // inserting in middle of linked list
    while (curr != NULL)
    {
        len++;
        if (len == pos)
        {
            Node *in = new Node(data);
            in->next = curr->next;
            curr->next = in;
            return head;
        }
        curr = curr->next;
    }
    // inserting at the end coz linked list is now null
    if (pos > len + 1)
    {
        cout << "position doesn't exist" << endl;
        return NULL;
    }
    Node *in = new Node(data);
    curr->next = in;
    return head;
}
int search(Node *head, int x) // iterative search in linked list O(n)-time complexity
{
    Node *curr = head;
    int index = 0;
    while (curr)
    {
        index++;
        if (curr->data == x)
            return index;
        curr = curr->next;
    }
    return (-1);
}

Node *recReverse(Node *head) // recursively reversing a linked list
{
    // base case
    if (head == NULL || head->next == NULL) // only one head node or no node
    {
        return head;
    }
    // otherwise
    Node *smallHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}
Node *iterativeReverse(Node *head)
{
    // we create 3 variables prev(P), current(c) and temp(T) which will itreate thorugh the entire linked list
    // and PCT will go on inside loop
    // P will be null initially and C will be head and T will be next of head
    // now we will first store the next of head in temp T so that it is not lost and then change the next of
    //  head to prev(P) , now to shift the PCT we will do P=C and C=T
    // when the entire linked list has been traversed the new head will be stored in the prev thus we make
    // head= prev
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // reverse the first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;
    int count = 1;
    // 1 2 3 4 5 6 7 8
    while (curr && count <= k) // this entire part is same as the iterative reverse just we will include
    // counter to count the no of nodes to be reversed each time
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    // 3 2 1 (4 5 6 7 8)- in temp
    // after the while loop ends the first set of k nodes has been reversed and the remaining is stored in
    // temp. so we will check if temp is NULL of not, if not NULL then we will recursively call the kReverse
    // function until the temp isn't NULL
    // this way we will have sets of reversed nodes
    // and we will connect them using head->next since
    if (temp != NULL)
    {
        head->next = kReverse(temp, k); // in 3 2 1, 1 was the head, since we did not update it so we
        // connect the next node set as head->next
    }
    return prev; // the new first node 3 will be in prev so we return prev
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head); // traversing and printing linked list
    rPrint(head);    // recursive traversal in linked list
    cout << endl;
    cout << "insert at begin:   ";
    head = insertBegin(head, 40); // insertion of 40 at beginning of linked list
    printList(head);
    cout << "insert at end:     ";
    head = insertEnd(head, 50); // inserted 50 at end of linked list
    printList(head);
    cout << "delete head node:      ";
    head = delHead(head); // delete the 1st node of linked list
    printList(head);
    cout << "delete tail node:     ";
    head = delTail(head); // delete the last node of linked list
    printList(head);
    cout << "insert at position:     ";
    head = insertAtPosition(head, 2, 100); // insert at a given position
    printList(head);
    int pos = search(head, 100); // searching index/position of 100 in linked list
    cout << "Index of searched value is:      " << pos << endl;
    head = recReverse(head); // recursivley reverse the linked list
    cout << "reversed list :  ";
    printList(head);
    head = iterativeReverse(head); // itratively reverse the linked list
    cout << "reversed list :  ";
    printList(head);
    head = kReverse(head, 2);
    cout << "reversing 2 nodes at a time: K reverse:  ";
    printList(head);
    return 0;
}