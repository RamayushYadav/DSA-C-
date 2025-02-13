// Inorder Predecessor And Sucessor
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

Node *BuildBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = BuildBST(root->right, d);
    }
    else
    {
        root->left = BuildBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}

void inOrder(Node *root, vector<int> &vec)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, vec);
    vec.push_back(root->data);
    cout << root->data << " ";
    inOrder(root->right, vec);
}

int predecessor(vector<int> vec, int pred)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == pred)
        {
            return vec[i - 1];
        }
    }
}

int successor(vector<int> vec, int suce)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == suce)
        {
            return vec[i + 1];
        }
    }
}

// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Base case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }
    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main()

{
    Node *root = NULL;
    takeInput(root);
    vector<int> V;
    inOrder(root, V);
    cout << endl;
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
    int node = 30;
    cout << "The Inorder predecessor of " << node << " is " << predecessor(V, node) << endl;
    cout << "The Inorder sucessor of " << node << " is " << successor(V, node) << endl;

    Node *pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, 30);
    if (pre != NULL)
        cout << "Predecessor is " << pre->data << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->data;
    else
        cout << "No Successor";
    return 0;
}