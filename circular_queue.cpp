#include <bits/stdc++.h>
using namespace std;
class QueueFullException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nQueue is full\n";
    }
};
class QueueEmptyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nQueue is empty\n";
    }
};
//generic implementation of Circular Queue data structure using templates
template <class T>
class Circular_Queue
{
  private:
    static const int MAX = 3;
    T data[MAX];
    int front, rear;

  public:
    Circular_Queue()
    {
        rear = front = -1;
    }
    void Enqueue(const T element)
    {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        {
            QueueFullException e;
            throw e;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == MAX - 1)
                rear = 0;
            else
                rear++;
        }
        data[rear] = element;
    }
    T Dequeue()
    {
        if (front == -1)
        {
            QueueEmptyException e;
            throw e;
        }
        T deleted = data[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == MAX - 1)
                front = 0;
            else
                front++;
        }
        return deleted;
    }
    T Front()
    {
        if (isEmpty())
        {
            QueueEmptyException e;
            throw e;
        }
        else
        {
            return data[front];
        }
    }
    int Size()
    {
        if (front <= rear)
            return rear - front + 1;
        else
            return MAX + rear - front + 1;
    }
    bool isEmpty()
    {
        return (front == -1);
    }
};

int main()
{
    Circular_Queue<int> q;
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    // Enqueue elements
    q.Enqueue(100);
    q.Enqueue(200);
    q.Enqueue(300);
    // Size of queue
    cout << "Size of queue = " << q.Size() << endl;
    // Front element
    cout << q.Front() << endl;
    // Dequeue elements
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    return 0;
}