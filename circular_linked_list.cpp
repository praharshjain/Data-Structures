#include <iostream>
using namespace std;
//generic implementation of Circular Singly Linked List using templates
template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class Circular_LinkedList
{
  private:
    int size;
    struct node<T> *start;

  public:
    Circular_LinkedList()
    {
        size = 0;
        start = NULL;
    }
    struct node<T> *create_node(const T value)
    {
        struct node<T> *temp = new (struct node<T>);
        temp->next = NULL;
        temp->data = value;
        return temp;
    }
    void insert(const T value)
    {
        struct node<T> *temp = start;
        if (temp != NULL)
        {
            temp = start->next;
            start->next = create_node(start->data);
            start->next->next = temp;
            start->data = value;
        }
        else
        {
            temp = create_node(value);
            start = temp;
            temp->next = start;
        }
        size++;
    }
    int search(const T value)
    {
        struct node<T> *temp = start;
        for (int pos = 1; temp != NULL; pos++)
        {
            if (temp->data == value)
            {
                return pos;
            }
            temp = temp->next;
        }
        return -1;
    }
    void remove_pos(const int pos)
    {
        if (pos <= size)
        {
            struct node<T> *curr = NULL, *temp = start;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            temp->data = temp->next->data;
            curr = temp->next;
            temp->next = curr->next;
            delete curr;
            size--;
        }
        else
        {
            cout << "\nNo such entry in list\n";
        }
    }
    void remove(const T value)
    {
        remove_pos(search(value));
    }
    // getters
    int getSize()
    {
        return size;
    }
    struct node<T> *getStart()
    {
        return start;
    }
};

int main()
{
    Circular_LinkedList<int> ll;
    ll.insert(5);
    ll.insert(6);
    ll.insert(78);
    ll.insert(54);
    ll.insert(8);
    ll.insert(7);
    //7 8 54 78 6 5
    struct node<int> *temp, *start = ll.getStart();
    temp = start;
    do
    {
        cout << temp->data << "\n";
        temp = temp->next;
    } while (temp != start);
    cout << "\nsize=" << ll.getSize() << "\n";
    cout << "\n78 found at position: " << ll.search(78) << "\n";
    ll.remove(78);
    ll.remove(54);
    ll.remove(7);
    //8 6 5
    start = ll.getStart();
    temp = start;
    do
    {
        cout << temp->data << "\n";
        temp = temp->next;
    } while (temp != start);
    cout << "\nsize=" << ll.getSize() << "\n";
    ll.insert(-1);
    ll.insert(34);
    //34 -1 8 6 5
    start = ll.getStart();
    temp = start;
    do
    {
        cout << temp->data << "\n";
        temp = temp->next;
    } while (temp != start);
    cout << "\nsize=" << ll.getSize() << "\n";
    return 0;
}