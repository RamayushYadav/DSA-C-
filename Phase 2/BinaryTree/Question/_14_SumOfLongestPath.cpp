// Sum Of The Longest Blood Line Of The Tree
//           4
//         /   \
//        2     5
//       / \   / \
//      7   1 2   3
//         /
//        6
//  sum  = 13
// 4  2  7  -1  -1  1  6  -1  -1  -1  5  2  -1  -1  3  -1  -1

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
    cout << "Enter the data ";
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

void solve(Node *root, int sum, int &maxSum, int len, int &maxlen)
{
    // base case
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }

        if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxlen);
    solve(root->right, sum, maxSum, len + 1, maxlen);
}

int SumOfLongestPath(Node *root)
{
    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxSum = INT32_MIN;

    solve(root, sum, maxSum, len, maxlen);

    return maxSum;
}

int main()

{
    Node *root = BuildBinaryTree(root);

    cout << "The Longest Path " << SumOfLongestPath(root)<< endl;

    return 0;
}