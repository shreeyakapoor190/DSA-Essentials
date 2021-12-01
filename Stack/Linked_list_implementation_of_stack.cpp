#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// insertion and deletion takes place from the same end in a stack
// to maintain this, we will make insertion and deletion at the HEAD NODE in case of singly linked list
// bcoz we will always pass the head pointer of the linked list in the function hence all the
// operations can be done in O(1) time complexity

// in case of doubly linked list, we can maintain tail pointer, and then all insertion and deletion can
// take place at the tail pointer
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
}; // struct node will be craeting the nodes of the linked list
struct MyStack
{
    Node *head;
    int sz; // no of nodes/elements in the stack currently present
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int x) // inserting node at the head of linked list
    {
        Node *temp = new Node(x); // allocate memory for new node
        temp->next = head;
        head = temp;
        sz++; // after every push we increment the size by 1
    }
    int pop() // deletion of head node and returning its value
    {
        if (head == NULL) // to handle underflow
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp); // deallocating memory
        sz--;          // decrementing the size of stack after pop
        return res;
    }
    int size() // return size of stack
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    int peek()
    {
        if (head == NULL) // to handle underflow
            return INT_MAX;
        return head->data;
    }
};
int main()
{
    MyStack s;
    s.push(5);                   // 5
    s.push(10);                  // 5 10
    s.push(20);                  // 5 10 20
    cout << s.pop() << endl;     // 5 10 (prints 20)
    cout << s.peek() << endl;    // 10
    cout << s.isEmpty() << endl; // false = 0
    return 0;
}