// Maximum Sum Of Non Adjacent Nodes
//       1
//      /  \
//     2    3
//    /    /  \
//   4    5    6
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
    cout << "Enter the data  -> ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

pair<int, int> solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> result;

    result.first = root->data + left.second + right.second;

    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main()

{
    Node *root = BuildBinaryTree(root);

    cout << "ANSWER IS -> " << getMaxSum(root) << endl;
    return 0;
}