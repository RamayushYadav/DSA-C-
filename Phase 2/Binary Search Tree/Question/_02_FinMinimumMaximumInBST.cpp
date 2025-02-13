// Find Minimum And Maximum In Binary Search Tree
/*
             10
            /  \
           8    21
          /      \
         7        27
        /
       5
      /
     4
    /
   3
*/
// input = 10 8 21 7 27 5 4 3 -1
#include<iostream>
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

void InputInBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

Node *FindMinimum(Node *root)
{
    Node *temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node *FindMaximum(Node *root)
{
    Node *temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

int main()
{
    Node *root = NULL;
    InputInBST(root);

    cout << "Minimum element in BST is "<<FindMinimum(root)->data<<endl;
    cout << "Maximum element in BST is "<<FindMaximum(root)->data<<endl;

    return 0;
}