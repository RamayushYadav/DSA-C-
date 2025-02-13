// Tree From PostOrder And InOrder
/*
    N = 8
    in[] = 4 8 2 5 1 6 3 7
  post[] = 8 4 5 2 6 7 3 1

       1
     /   \
    2     3
   / \   / \
  4   5 6   7
  \
   8
  output = 1 2 4 8 5 3 6 7
*/
#include <iostream>
#include <map>
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

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // create a root node for element
    int element = post[index--];
    Node *root = new Node(element);
    // find element's index in inorder
    int position = nodeToIndex[element];

    // recursive calls [in case of postorder and inorder , we first build the right subtree]
    root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);

    return root;
}

Node *BuildTree(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    // create  mapping
    createMapping(in, nodeToIndex, n);

    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()

{
    int N = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *root = BuildTree(in, post, N);

    PreOrder(root);
    return 0;
}