// Inorder Predecessor AND Inorder Successor
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

// recursive approach
Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < P->data && root->data < Q->data)
    {
        return LCAinaBST(root->right, P, Q);
    }

    if (root->data > P->data && root->data > Q->data)
    {
        return LCAinaBST(root->left, P, Q);
    }

    return root;
}

/*
// iterative approach
Node *LCAinaBST(Node *root,Node *P,Node *Q)
{
    while(root != NULL)
    {
    if(root->data < P->data && root->data < Q->data)
    {
        root = root->right;
    }
    else if(root->data > P->data && root->data > Q->data)
    {
        root = root->left;
    }
    else
    {
        return root;
    }
    }
}
*/

int main()

{
    Node *root = NULL;
    takeInput(root);
    // 50 20 70 10 30 90 110 -1
    Node *P = new Node(3);
    Node *Q = new Node(7);
    cout << "The Lowest Common Ancestor of " << P->data << " AND " << Q->data << " is " << LCAinaBST(root, P, Q)->data << endl;
    return 0;
}