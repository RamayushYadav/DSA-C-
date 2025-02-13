// // Basic operation in binary tree(implementation of binary tree)
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
#include <iostream>
#include <queue>
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

Node *buildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}


int main()

{
    Node *root = NULL;

    // Creating a tree
    root = buildBinaryTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    Inorder(root);

    return 0;
}