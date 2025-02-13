// Height of Binary Tree
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// 7 4 7 1 5 6 2 8 4 6 3 4 N N N N N N N N N N N N N
#include <iostream>
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

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left pointer : " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the data for right pointer : " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

// void LevelOrderTraversal(Node *root, int &count)
// {
//     queue<Node *> q;
//     q.push(root);

//     // separator
//     q.push(NULL);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();
//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(temp);
//             }
//             count++;
//         }
//         else
//         {
//             // cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }

//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Height(root->left);
    int right = Height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int main()

{
    Node *root = NULL;

    root = BuildBinaryTree(root);

    cout << "Height of the binary tree is " << CountHeight(root) << endl;

    return 0;
}