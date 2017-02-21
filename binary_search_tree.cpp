#include <bits/stdc++.h>
using namespace std;
//generic implementation of Binary Search Tree using templates
template <class T>
struct node
{
    T data;
    struct node *left;
    struct node *right;
};
template <class T>
class BST
{
  private:
    int size;
    struct node<T> *root;

  public:
    BST()
    {
        size = 0;
        root = NULL;
    }
    struct node<T> *create_node(const T value)
    {
        struct node<T> *temp = new (struct node<T>);
        temp->left = NULL;
        temp->right = NULL;
        temp->data = value;
        return temp;
    }
    //insertion in binary serach tree
    void insert(const T value)
    {
        struct node<T> *newnode = create_node(value);
        if (root == NULL)
            root = newnode;
        else
        {
            struct node<T> *temp = root;
            while (true)
            {
                if (value > temp->data)
                {
                    if (temp->right)
                        temp = temp->right;
                    else
                    {
                        temp->right = newnode;
                        break;
                    }
                }
                else
                {
                    if (temp->left)
                        temp = temp->left;
                    else
                    {
                        temp->left = newnode;
                        break;
                    }
                }
            }
        }
        size++;
    }
    void inorder(struct node<T> *tree)
    {
        if (tree)
        {
            inorder(tree->left);
            cout << tree->data << "\n";
            inorder(tree->right);
        }
    }
    void preorder(struct node<T> *tree)
    {
        if (tree)
        {
            cout << tree->data << "\n";
            preorder(tree->left);
            preorder(tree->right);
        }
    }
    void postorder(struct node<T> *tree)
    {
        if (tree)
        {
            postorder(tree->left);
            postorder(tree->right);
            cout << tree->data << "\n";
        }
    }
    void levelorder(struct node<T> *root)
    {
        queue<struct node<int> *> q;
        q.push(root);
        while (q.size())
        {
            struct node<T> *temp = q.front();
            q.pop();
            cout << temp->data << "\n";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    void traverse(int i = 1)
    {
        switch (i)
        {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            levelorder(root);
            break;
        default:
            inorder(root);
        }
    }
    int height(struct node<T> *tree)
    {
        if (tree == NULL)
            return 0;
        else
            return max(height(tree->left), height(tree->right)) + 1;
    }
    int height()
    {
        return height(root);
    }
    int Size()
    {
        return size;
    }
};
int main()
{
    BST<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(0);
    tree.insert(-2);
    tree.insert(-5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(10);
    cout << "Size = " << tree.Size() << "\n";
    cout << "Height = " << tree.height() << "\n";
    cout << "Inorder traversal\n";
    tree.traverse();
    cout << "Preorder traversal\n";
    tree.traverse(2);
    cout << "Postorder traversal\n";
    tree.traverse(3);
    cout << "Level order traversal\n";
    tree.traverse(4);
}