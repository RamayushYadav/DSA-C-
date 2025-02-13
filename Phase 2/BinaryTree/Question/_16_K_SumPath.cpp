// k Sum Paths
//      1
//     / \
//    2   3
//   k = 3
// 1)  1 + 2 = 3
// 2)  right leaf node = 3
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
    cout << "Enter the left Node of " << data << endl;
    root->left = BuildBinaryTree(root->left);
    cout << "Enter the right Node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

void solve(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    // check for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}

int SumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main()
{
    Node *root = BuildBinaryTree(root);

    cout << "The possilbe number of path for the value of k are -> " << SumK(root, 5) << endl;

    return 0;
}