// LRN (Post order traversal)
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

Node *BuilBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node of the " << data << endl;
    root->left = BuilBinaryTree(root->left);

    cout << "Enter the right node of the " << data << endl;
    root->right = BuilBinaryTree(root->right);

    return root;
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()

{
    Node *root = NULL;

    root = BuilBinaryTree(root);

    PostOrder(root);
    return 0;
}