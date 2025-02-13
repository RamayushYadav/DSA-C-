// Validate Binary Search Tree
/*
             50
            /  \
          20    70
         / \     \
       10  30    90
                   \
                   110
*/
#include <iostream>
#include <climits>
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

Node *buildBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = buildBST(root->right, d);
    }

    else
    {
        root->left = buildBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

bool isBST(Node *root, int min, int max)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    if (root->data > min && root->data < max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        return left && right;
    }

    return false;
}

bool ValidateBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()

{
    Node *root = NULL;

    takeInput(root);

    if (ValidateBST(root))
    {
        cout << "IT IS BINARY SEARCH TREE" << endl;
    }
    else
    {
        cout << "IT IS NOT BINARY SEARCH TREE" << endl;
    }
    return 0;
}