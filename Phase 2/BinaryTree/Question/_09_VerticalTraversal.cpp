// Vertical Traversal
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// output =  4 2 1 5 3 6
// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue
#include <bits/stdc++.h>
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

vector<int> VerticalOrder(Node *root)
{
    // make map for inserting the datas in level order
    map<int, map<int, vector<int>>> nodes;
    // insert the data in a horizonal distance order
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    // for root node  // in the root level and horizontal distance is zero
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second.first;   // horizontal distance
        int lvl = temp.second.second; // level

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    // i <int(hd),map(int,vector)>
    for (auto i : nodes)
    {
        // j = i.second(map(int,vector))
        for (auto j : i.second)
        {
            // k = j.second (vector)
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

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
    cout << "Enter the left node for data " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node for data " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

int main()

{
    Node *root = NULL;
    root = BuildBinaryTree(root);

    vector<int> vertorder = VerticalOrder(root);

    for (int i = 0; i < vertorder.size(); i++)
    {
        cout << vertorder[i] << " ";
    }

    return 0;
}


// Initialization:

// nodes map is created to store data based on horizontal distance and level.
// q queue is initialized to perform level order traversal.
// ans vector will store the final result.
// Root Node (1):

// Push root (1) to the queue with hd = 0 and lvl = 0.
// Process root and update nodes: nodes[0][0] = {1}.
// Queue After First Iteration:

// Queue: empty (root processed).
// Queue After Second Iteration (for Node 2):

// Push left child (2) with hd = -1 and lvl = 1.
// Push right child (3) with hd = 1 and lvl = 1.
// Queue After Third Iteration (for Node 4 and 5):

// Push left child of 2 (4) with hd = -2 and lvl = 2.
// Push right child of 2 (5) with hd = 0 and lvl = 2.
// Queue After Fourth Iteration (for Node 6):

// Push right child of 3 (6) with hd = 2 and lvl = 2.
// Final nodes Map:

// nodes[-2][2] = {4}
// nodes[-1][1] = {2}
// nodes[0][0] = {1}
// nodes[0][2] = {5}
// nodes[1][1] = {3}
// nodes[2][2] = {6}
// Final Result (ans vector):

// Concatenate the vectors from the nodes map in horizontal distance order:
// Result: [4, 2, 1, 5, 3, 6]
// So, the final vertical order traversal of the given tree is [4, 2, 1, 5, 3, 6].
