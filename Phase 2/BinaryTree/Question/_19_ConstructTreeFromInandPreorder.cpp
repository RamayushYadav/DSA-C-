// Construct Tree From Inorder And PreOrder
/*
  N = 6
  inorder[] = {3,1,4,0,5,2}
  preorder[] = {0,1,3,4,2,5}

  output --> 3 4 1 5 2 0
        0
      /   \
    1      2
   / \    /
  3  4   5
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

int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}


Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    // base case(pre ka array size ke bahar chale jaye and start and end se aage chala jaye)
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // inorder main position find karna
    //create a root for element
    int element = pre[index++];
    Node *root = new Node(element);
    // find element's index in inorder
    int position = findPosition(in, element, n);

    // recursive calls
    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}

Node *BuildTree(int in[], int pre[], int n)
{
    int preorderIndex = 0;
    Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()

{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 6;
    Node *root = BuildTree(in, pre, n);

    PostOrder(root);

    return 0;
}