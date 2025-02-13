// LNR (Inorder Traversal)
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
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
    cout << "Enter the data  : ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

void InorderTraversal(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

int main()

{
    Node *root = NULL;

    root = BuildBinaryTree(root);

    InorderTraversal(root);

    return 0;
}