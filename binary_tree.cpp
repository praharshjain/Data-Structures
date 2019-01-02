#include <bits/stdc++.h>
using namespace std;
//generic implementation of Binary Tree using templates
template <class T>
struct node
{
    T data;
    struct node *left;
    struct node *right;
};
template <class T>
class BinaryTree
{
    private:
        int size;
        struct node<T> *root;
        queue<struct node<T> *> q;

    public:
        BinaryTree()
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
        //insertion in complete binary tree
        void insert(const T value)
        {
            struct node<T> *temp = create_node(value);
            if (root == NULL)
                root = temp;
            else
            {
                struct node<T> *front = q.front();
                if (front->left == NULL)
                    front->left = temp;
                else if (front->right == NULL)
                    front->right = temp;
                if (front->left && front->right)
                    q.pop();
            }
            q.push(temp);
            size++;
        }
        //tree properties
        int height(struct node<T> *tree)
        {
            if (tree == NULL)
                return 0;
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
        //traversal
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
        void levelorder(struct node<T> *tree)
        {
            queue<struct node<T> *> q;
            q.push(tree);
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
            case 1: //bfs
                inorder(root);
                break;
            case 2: //bfs
                preorder(root);
                break;
            case 3: //bfs
                postorder(root);
                break;
            case 4: //dfs
                levelorder(root);
                break;
            default:
                inorder(root);
            }
        }
        //misc.
        void leafnodes(struct node<T> *tree)
        {   if(tree)
            {
                if(tree->left == NULL && tree->right == NULL)
                {
                    cout << tree->data << "\n";
                }
                leafnodes(tree->left);
                leafnodes(tree->right);
            }
        }
        void leafnodes()
        {
            leafnodes(root);
        }
        int diameter(struct node<T> *tree, int *height)
        {
            int lheight = 0, rheight = 0, ldiameter = 0, rdiameter = 0;
            if(tree == NULL)
            {
                *height = 0;
                return 0; // diameter is also 0
            }
            ldiameter = diameter(tree->left, &lheight);
            rdiameter = diameter(tree->right, &rheight);
            *height = max(lheight, rheight) + 1;
            return max(lheight + rheight + 1, max(ldiameter, rdiameter));
        }
        int diameter()
        {
            int height = 0;
            return diameter(root, &height);
        }
        void leftview(struct node<T> *tree, int level, int *maxlevel)
        {
            if(tree)
            {
                if(*maxlevel < level)
                {
                    cout << tree->data << "\n";
                    *maxlevel = level;
                }
                leftview(tree->left, level + 1, maxlevel);
                leftview(tree->right, level + 1, maxlevel);
            }
        }
        void leftview()
        {
            int maxlevel = 0;
            leftview(root, 1, &maxlevel);
        }
        void rightview(struct node<T> *tree, int level, int *maxlevel)
        {
            if(tree)
            {
                if(*maxlevel < level)
                {
                    cout << tree->data << "\n";
                    *maxlevel = level;
                }
                rightview(tree->right, level + 1, maxlevel);
                rightview(tree->left, level + 1, maxlevel);
            }
        }
        void rightview()
        {
            int maxlevel = 0;
            rightview(root, 1, &maxlevel);
        }
        void topbottomview(struct node<T> *tree, string view = "top")
        {
            map<int, T> m;
            queue<pair<struct node<T> *, int> > q;
            pair<struct node<T> *, int> p = make_pair(tree, 0);
            q.push(p);
            while (q.size())
            {
                p = q.front();
                q.pop();
                struct node<T> *temp = p.first;
                int level = p.second;
                if(m.count(level) == 0 || view == "bottom")
                {
                    m[level] = temp->data;
                }
                if (temp->left)
                {
                    p = make_pair(temp->left, level - 1);
                    q.push(p);
                }
                if (temp->right)
                {
                    p = make_pair(temp->right, level + 1);
                    q.push(p);
                }
            }
            for(typename map<int, T>::iterator it = m.begin(); it != m.end(); it++)
            {
                cout << it->second << "\n";
            }
        }
        void topview()
        {
            topbottomview(root);
        }
        void bottomview()
        {
            topbottomview(root, "bottom");
        }
};
int main()
{
    BinaryTree<int> tree;
    for (int i = 0; i <= 7; i++)
        tree.insert(i);
    /*
    tree looks like -
           0
         /   \
        1     2
       / \   / \
      3   4  5  6
     /
    7
    */
    cout << "Size = " << tree.Size() << "\n";
    cout << "Height = " << tree.height() << "\n";
    cout << "Diameter = " << tree.diameter() << "\n";
    cout << "Inorder traversal\n";
    tree.traverse();
    cout << "Preorder traversal\n";
    tree.traverse(2);
    cout << "Postorder traversal\n";
    tree.traverse(3);
    cout << "Level order traversal\n";
    tree.traverse(4);
    cout << "Leaf nodes\n";
    tree.leafnodes();
    cout << "Left view\n";
    tree.leftview();
    cout << "Right view\n";
    tree.rightview();
    cout << "Top view\n";
    tree.topview();
    cout << "Bottom view\n";
    tree.bottomview();
}