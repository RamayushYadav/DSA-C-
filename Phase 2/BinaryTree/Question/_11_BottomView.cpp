// Top View Of Binary Tree
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// output =  4 2 5 3 6
#include <iostream>
#include <queue>
#include <vector>
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

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data  ";
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

vector<int> BottomView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    map<int, int> BottomNode;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

            BottomNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : BottomNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()

{
    Node *root = BuildBinaryTree(root);

    vector<int> bottomView = BottomView(root);

    for (int i = 0; i < bottomView.size(); i++)
    {
        cout << bottomView[i] << " ";
    }
    return 0;
}
