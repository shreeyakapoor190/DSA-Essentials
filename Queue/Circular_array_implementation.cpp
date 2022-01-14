#include <iostream>
using namespace std;
struct Queue
{
    int size, cap, front;
    int *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[(front + size - 1) % cap];
    }
    void enque(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
            return;
        // int i;
        // for (i = 0; i < size - 1; i++)
        // {
        //     arr[i] = arr[i + 1];
        // }
        front = (front + 1) % cap;
        size--;
    }
};
int main()
{
    Queue q(10);
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    q.enque(1);
    q.enque(2);
    q.dequeue();
    q.enque(10);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}
