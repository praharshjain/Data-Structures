#include <bits/stdc++.h>
using namespace std;
//generic implementation of Max Heap using array
template <class T>
struct node
{
    T data;
    struct node *left;
    struct node *right;
};
template <class T>
class MaxHeap
{
    private:
        unsigned int size;
        unsigned int capacity;
        T *arr;

    public:
        MaxHeap(unsigned int heapsize)
        {
            capacity = heapsize;
            size = 0;
            arr = new T[capacity];
        }
        unsigned int parent(unsigned int i)
        {
            return (i > 0 ? (i - 1) / 2 : 0);
        }
        unsigned int leftchild(unsigned int i)
        {
            unsigned int l = (2 * i) + 1;
            return (l  < size ? l : size);
        }
        unsigned int rightchild(unsigned int i)
        {
            unsigned int r = (2 * i) + 2;
            return (r  < size ? r : size);
        }
        T getMax()
        {
            return (size > 0 ? arr[0] : NULL);
        }
        void swap(T *x, T *y)
        {
            T temp = *x;
            *x = *y;
            *y = temp;
        }
        void maxHeapify(unsigned int rootIndex)
        {
            unsigned int l = leftchild(rootIndex);
            unsigned int r = rightchild(rootIndex);
            unsigned int largest = rootIndex;
            if (l < size && arr[l] > arr[rootIndex])
            {
                largest = l;
            }
            if (r < size && arr[r] > arr[largest])
            {
                largest = r;
            }
            if (largest != rootIndex)
            {
                swap(&arr[rootIndex], &arr[largest]);
                maxHeapify(largest);
            }
        }
        T extractMax()
        {
            if (size <= 0)
            {
                return NULL;
            }
            if (size == 1)
            {
                size--;
                return arr[0];
            }
            T root = arr[0];
            arr[0] = arr[--size];
            maxHeapify(0);
            return root;
        }
        void increase(unsigned int i, T newVal, bool setToMax = false)
        {
            arr[i] = newVal;
            while (i != 0 && (arr[parent(i)] < arr[i] || setToMax))
            {
                swap(&arr[i], &arr[parent(i)]);
                i = parent(i);
            }
        }
        void remove(unsigned int i)
        {
            increase(i, NULL, true);
            extractMax();
        }
        void insert(T k)
        {
            if (size >= capacity)
            {
                cout << "\nOverflow: Could not insertKey\n";
                return;
            }
            size++;
            int i = size - 1;
            arr[i] = k;
            while(i != 0 && arr[parent(i)] < arr[i])
            {
                swap(&arr[i], &arr[parent(i)]);
                i = parent(i);
            }
        }
        void traverse()
        {
            cout << "\n";
            for(unsigned int i = 0; i < size; i++)
            {
                cout << arr[i] << "\n";
            }
        }
};
int main()
{
    MaxHeap<int> heap = MaxHeap<int>(10);
    heap.insert(8);
    heap.insert(5);
    heap.insert(6);
    heap.insert(9);
    heap.insert(1);
    heap.insert(3);
    heap.traverse();
    cout << "Max = " << heap.extractMax() << "\n";
    heap.traverse();
    cout << "Max = " << heap.getMax() << "\n";
    heap.remove(3);
    heap.traverse();
    heap.insert(10);
    heap.traverse();
    return 0;
}