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

Node *buildBST(Node *root,int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
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

    while(data != -1)
    {
        root = buildBST(root,data);
        cin >> data;
    }
}

pair<int,int> predecessorSuccessor(Node *root,int key)
{
    // find key
    Node *temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key)
    {
        // key is small
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            // key is greater
            pred = temp->data;
            temp = temp->right;
        }
    }

    // pred and succ

    // pred
    Node *leftTree = temp->left;
    while(leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ
    Node *rightTree = temp->right;
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int> ans = make_pair(pred,succ);

    return ans;
}

int main()

{
    Node *root  = NULL;
    takeInput(root);

    pair<int,int> inorder = predecessorSuccessor(root,30);
    cout << "Inorder predecessor is "<<inorder.first << endl;
    cout << "Inorder Successor is "<<inorder.second << endl;

    return 0;
}