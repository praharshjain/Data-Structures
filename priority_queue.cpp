#include <iostream>
#define MAX_N 1000001
using namespace std;
/*  Generic priority queue implementation using min-heap
    Complexity: O(log N) for push/pop, O(1) for isEmpty/GetMinimum
*/
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
template <class T>
class Priority_Queue
{
  private:
    T PQ[MAX_N];
    int heap_size;

  public:
    Priority_Queue()
    {
        heap_size = 0;
    }
    bool isEmpty()
    {
        return (heap_size <= 0);
    }

    T GetMinimum()
    {
        if (isEmpty())
        {
            QueueEmptyException e;
            throw e;
        }
        return PQ[1];
    }

    void push(T x)
    {
        if (heap_size >= MAX_N)
        {
            QueueFullException e;
            throw e;
        }
        PQ[++heap_size] = x;
        int pos = heap_size;
        while (pos > 1 && PQ[pos / 2] > PQ[pos])
        {
            swap(PQ[pos / 2], PQ[pos]);
            pos /= 2;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            QueueEmptyException e;
            throw e;
        }
        int ret, left, right, pos = 1;
        swap(PQ[pos], PQ[heap_size--]);
        while (pos <= heap_size)
        {
            ret = pos;
            left = pos * 2;
            right = pos * 2 + 1;
            if (left <= heap_size && PQ[left] < PQ[ret])
                ret = left;
            if (right <= heap_size && PQ[right] < PQ[ret])
                ret = right;
            if (ret != pos)
            {
                swap(PQ[pos], PQ[ret]);
                pos = ret;
            }
            else
                break;
        }
    }
};

int main()
{
    Priority_Queue<int> q;
    q.push(80);
    q.push(-5);
    q.push(13);
    q.push(0);
    while (!q.isEmpty())
    {
        cout << q.GetMinimum() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}