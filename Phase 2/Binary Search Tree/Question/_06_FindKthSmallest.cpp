// Find Kth Smallest Element in Binary Search Tree
/*
             50
            /  \
          20    70
         / \     \
       10  30    90
                   \
                   110
*/
// inorder = 10 20 30 50 70 90 110
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

int solve(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // L
    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

int kthSmallestElement(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{
    Node *root = NULL;

    takeInput(root);

    int K = 4;
    int smallest = kthSmallestElement(root, K);

    cout << K << "th smallest element of BST is " << smallest << endl;
    return 0;
}
