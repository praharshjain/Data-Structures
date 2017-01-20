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
//generic implementation of standard Queue data structure using templates
template <class T>
class Queue
{
  private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int front;
    int rear;

  public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

    void Enqueue(const T element)
    {
        if (Size() == MAX_SIZE - 1)
        {
            QueueFullException e;
            throw e;
        }
        else
        {
            data[rear] = element;
            rear = ++rear % MAX_SIZE;
        }
    }

    T Dequeue()
    {
        if (isEmpty())
        {
            QueueEmptyException e;
            throw e;
        }
        else
        {
            T ret = data[front];
            front = ++front % MAX_SIZE;
            return ret;
        }
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
        return abs(rear - front);
    }

    bool isEmpty()
    {
        return (front == rear) ? true : false;
    }
};

int main()
{
    Queue<int> q;
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