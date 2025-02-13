// count leaf nodes in binary tree
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
    cout << "enter the data : ";
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

void InOrder(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left, count);
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        // cout << "Leaf Nodes are " << root->data << endl;
        count++;
    }

    InOrder(root->right, count);
}


int noOfLeafNodes(Node *root)
{
    int count = 0;
    InOrder(root, count);

    return count;
}

int main()
{
    Node *root = NULL;
    root = BuildBinaryTree(root);

    cout << "The Count is " << noOfLeafNodes(root) << endl;

    return 0;
}