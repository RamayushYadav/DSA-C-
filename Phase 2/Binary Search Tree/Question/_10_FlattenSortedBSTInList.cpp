// Flatten a Binary Search Tree In Sorted Order in form of list
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
#include <vector>
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

void inorder(Node *root, vector<int> &in)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node *flatten(Node *root)
{
    vector<int> inorderVal;
    // 1st step
    inorder(root, inorderVal);
    int n = inorderVal.size();

    Node *newRoot = new Node(inorderVal[0]);

    Node *curr = newRoot;

    // 2nd step
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(inorderVal[i]);
  
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd step
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
}

int main()

{
    Node *root = NULL;

    takeInput(root);

    Node *List = flatten(root);

    display(List);
}