#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_SIZE = 100;
//generic implementation of standard Queue data structure using templates
template <class T>
class Queue
{
  private:
    T data[MAX_SIZE];
    int front;
    int rear;

  public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

    void Enqueue(T element)
    {
        if (Size() == MAX_SIZE - 1)
            cout << "Queue full\n";
        data[rear] = element;
        rear = ++rear % MAX_SIZE;
    }

    int Dequeue()
    {
        if (isEmpty())
            cout << "Queue empty\n";
        T ret = data[front];
        front = ++front % MAX_SIZE;
        return ret;
    }

    int Front()
    {
        if (isEmpty())
            cout << "Queue empty\n";
        return data[front];
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