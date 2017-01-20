#include <iostream>
using namespace std;
class StackoverflowException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nStack overflow\n";
    }
};
class StackunderflowException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nStack underflow\n";
    }
};
//generic implementation of standard Stack data structure using templates
template <class T>
class Stack
{
  private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int top;

  public:
    Stack()
    {
        top = -1;
    }

    void Push(const T element)
    {
        if (top >= MAX_SIZE)
        {
            StackoverflowException e;
            throw e;
        }
        else
        {
            data[++top] = element;
        }
    }

    T Pop()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return data[top--];
        }
    }

    T Top()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return data[top];
        }
    }

    int Size()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return top + 1;
        }
    }

    bool isEmpty()
    {
        return (top <= -1) ? true : false;
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