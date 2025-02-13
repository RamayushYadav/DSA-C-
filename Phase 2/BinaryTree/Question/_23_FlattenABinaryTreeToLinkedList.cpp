// Flatten A Binary Tree To Linked List
/*
       1
     /   \
    2     5
   / \     \
  3   4     6
output -->  1 2 3 4 5 6
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

void flatten(Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred = current->left;

            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}

void Traversal(Node *root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}

int main()

{
    Node *root = BuildBinaryTree(root);
    flatten(root);
    Traversal(root);
    return 0;
}