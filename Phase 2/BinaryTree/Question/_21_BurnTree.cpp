// Tree From PostOrder And InOrder
/*
   target = 8

       1
     /   \
    2     3
   / \     \
  4   5     6
     / \     \
    7   8     9
               \
               10
  output = 7 second
*/
#include <iostream>
#include <map>
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

// step 1
Node *CreateParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *result = NULL;

    queue<Node *> q;
    q.push(root);
    // root ka parent null hai
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *Front = q.front();
        q.pop();

        if (Front->data == target)
        {
            result = Front;
        }

        if (Front->left)
        {
            nodeToParent[Front->left] = Front;
            q.push(Front->left);
        }
        if (Front->right)
        {
            nodeToParent[Front->right] = Front;
            q.push(Front->right);
        }
    }
    return result;
}

// step 2
int BurnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;
    int time = 0;
    // burn nehbouring nodes
    while (!q.empty())
    {
        // flag ko true mark kar denge agar addition hua ho toh
        bool flag = 0;
        int Size = q.size();
        for (int i = 0; i < Size; i++)
        {
            // process neibhouring nodes
            Node *Front = q.front();
            q.pop();
            //  existence front->left  or visited na ho pahale se
            if (Front->left && !visited[Front->left])
            {
                flag = 1;
                q.push(Front->left);
                visited[Front->left] = 1;
            }
            //  existence front->right  or visited na ho pahale se
            if (Front->right && !visited[Front->right])
            {
                flag = 1;
                q.push(Front->right);
                visited[Front->right] = 1;
            }
            // parent nodes existence
            if (nodeToParent[Front] && !visited[nodeToParent[Front]])
            {
                flag = 1;
                q.push(nodeToParent[Front]);
                visited[nodeToParent[Front]] = 1;
            }
        }
        if (flag == 1)
        {
            time++;
        }
    }
    return time;
}

int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = CreateParentMapping(root, target, nodeToParent);
    // ans == time
    int ans = BurnTree(targetNode, nodeToParent);
    return ans;
}

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data ";
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

int main()

{
    Node *root = BuildBinaryTree(root);
    cout << "Burn Time " << minTime(root, 8) << " second" << endl;

    return 0;
}