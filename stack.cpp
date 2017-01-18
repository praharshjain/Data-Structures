#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
//generic implementation of standard Stack data structure using templates
template <class T>
class Stack
{
  private:
    T data[MAX_SIZE];
    int top;

  public:
    Stack()
    {
        top = -1;
    }

    void Push(T element)
    {
        if (top >= MAX_SIZE)
        {
            cout << "Stack overflow\n";
        }
        data[++top] = element;
    }

    T Pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow\n";
        }
        return data[top--];
    }

    T Top()
    {
        return data[top];
    }

    int Size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }
};

int main()
{
    Stack<int> s;
    if (s.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    // Push elements
    s.Push(100);
    s.Push(200);
    // Size of stack
    cout << "Size of stack = " << s.Size() << endl;
    // Top element
    cout << s.Top() << endl;
    // Pop element
    cout << s.Pop() << endl;
    // Pop element
    cout << s.Pop() << endl;
    // Pop element
    cout << s.Pop() << endl;
    return 0;
}