#include <iostream>
using namespace std;
//generic implementation of Dobuly Linked List using templates
template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template <class T>
class Doubly_LinkedList
{
  private:
    int size;
    struct node<T> *start;

  public:
    Doubly_LinkedList()
    {
        size = 0;
        start = NULL;
    }
    struct node<T> *create_node(const T value)
    {
        struct node<T> *temp = new (struct node<T>);
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = value;
        return temp;
    }
    // functions to insert values
    void insert_begin(const T value)
    {
        struct node<T> *temp = create_node(value);
        if (start != NULL)
        {
            temp->next = start;
        }
        start = temp;
        size++;
    }
    void insert(const T value)
    {
        struct node<T> *temp = start;
        if (temp != NULL)
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = create_node(value);
            temp->next->prev = temp;
            size++;
        }
        else
        {
            insert_begin(value);
        }
    }
    void insert_pos(const T value, int pos)
    {
        if (pos == 1)
        {
            insert_begin(value);
        }
        else if (pos == size + 1)
        {
            insert(value);
        }
        else if (pos <= size)
        {
            struct node<T> *curr = create_node(value), *temp = start;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            curr->prev = temp;
            temp->next = curr;
            temp->next->prev = curr;
            size++;
        }
        else
        {
            cout << "\nInsertion at position " << pos << " is not possible\n";
        }
    }
    // search the list
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
    // delete from list
    void remove_pos(const int pos)
    {
        if (pos > 1 && pos <= size)
        {
            struct node<T> *curr = NULL, *temp = start;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            curr = temp->next;
            temp->next = curr->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp;
            }
            delete curr;
            size--;
        }
        else if (pos == 1 && size >= pos)
        {
            struct node<T> *temp = start->next;
            delete start;
            start = temp;
            start->prev = NULL;
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
    void reverse()
    {
        if (start != NULL && start->next != NULL)
        {
            struct node<T> *p1 = NULL, *curr = start, *p2 = start->next;
            while (p2 != NULL)
            {
                curr->next = p1;
                p1 = curr;
                curr = p2;
                p2 = p2->next;
            }
            curr->next = p1;
            start = curr;
        }
    }
    void sort()
    {
        T x;
        struct node<T> *p1 = NULL, *p2 = NULL, *last = NULL;
        if (start != NULL && start->next != NULL)
        {
            for (p1 = start; p1 != NULL; p1 = p1->next)
            {
                for (p2 = start; p2->next != last; p2 = p2->next)
                {
                    if (p2->data > p1->data)
                    {
                        x = p1->data;
                        p1->data = p2->data;
                        p2->data = x;
                    }
                    if (p2->next == last)
                    {
                        last = p2;
                    }
                }
            }
        }
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
    Doubly_LinkedList<int> ll;
    ll.insert_begin(5);
    ll.insert_begin(6);
    ll.insert(78);
    ll.insert_pos(54, 4);
    ll.insert_pos(8, 4);
    ll.insert_pos(7, 1);
    ll.insert_pos(8888, 12);
    //7 6 5 78 8 54
    struct node<int> *temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << "\n";
    cout << "\nsize=" << ll.getSize() << "\n";
    cout << "\n78 found at position: " << ll.search(78) << "\n";
    ll.remove(78);
    ll.remove_pos(5);
    ll.remove_pos(1);
    ll.remove_pos(10);
    //6 5 8
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << "\n";
    cout << "\nsize=" << ll.getSize() << "\n";
    ll.reverse();
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << "\n";
    cout << "\nsize=" << ll.getSize() << "\n";
    ll.insert(-1);
    ll.insert(34);
    ll.sort();
    //-1 5 6 8 34
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << "\n";
    cout << "\nsize=" << ll.getSize() << "\n";
    return 0;
}