// PreOrder Traversal Of Binary Search Tree
// arr[] = {20,10,5,15,13,35,30,42}
/*
       20
      /  \
     10   35
    / \   / \
   5  15 30  42
      /
     13
*/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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

Node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }

    // out of range
    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return NULL;
    }

    Node *root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

Node *PreOrderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()

{
    vector<int> V;
    V.push_back(20);
    V.push_back(10);
    V.push_back(5);
    V.push_back(15);
    V.push_back(13);
    V.push_back(35);
    V.push_back(30);
    V.push_back(42);

    Node *root = PreOrderToBST(V);
    levelOrderTraversal(root);
    return 0;
}