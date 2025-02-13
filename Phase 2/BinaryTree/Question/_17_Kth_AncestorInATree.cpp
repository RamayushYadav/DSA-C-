// Kth Ancestor In A Tree
//           4
//         /   \
//        2     5
//       / \   / \
//      7   1 2   3
//
//  k = 2 , n(node) = 7
// ans = 4
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

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data -> ";
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

Node *solve(Node *root, int &k, int node)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    // wapas
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock karne ke liye k ko high value di
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock karne ke liye k ko high value di
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int KthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    // 1 <= k <= 100
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()
{
    Node *root = BuildBinaryTree(root);
    cout << "The answer is " << KthAncestor(root, 1, 7) << endl;
    return 0;
}