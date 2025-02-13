// Deletion In Binary Search Tree
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
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = buildBST(root->right,d);
    }
    else
    {
        root->left = buildBST(root->left,d);
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

Node *FindMinimum(Node *root)
{
    Node *temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node *DeleteFromBST(Node *root,int val)
{
    // base case
    if(root == NULL)
    {
        return root;
    }
    
    if(root->data == val)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL)
        {
            int mini = FindMinimum(root->right)->data;
            // copy data
            root->data = mini;
            root->right = DeleteFromBST(root->right,mini);
            return root;
        }
    }

    else if(root->data > val)
    {
        // left part me jao
        root->left = DeleteFromBST(root->left,val);
        return root;
    }

    else
    {
        // right part me jao
        root->right = DeleteFromBST(root->right,val);
        return root;        
    }
}

void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()

{
    Node *root = NULL;
    takeInput(root);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
   
    // Node *temp = DeleteFromBST(root,30); 
    Node *temp = DeleteFromBST(root,90); 
    cout << "AFTER DELETION" << endl;
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}