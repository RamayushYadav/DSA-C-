// Zig Zag Traversal In Binary Tree
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// output =  1 3 2 4 5 6
#include <iostream>
#include <queue>
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
    cout << "Enter the data ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node for " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node for " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

vector<int> zigzagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    // lefToRight == true for left to right direction
    // leftToRight == false for right to left direction
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        // level process
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        // Direction Change karni hai
        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()

{
    Node *root = NULL;
    root = BuildBinaryTree(root);

    vector<int> trav = zigzagTraversal(root);
    // for (const auto &travs : trav)
    // {
    //     cout << travs << " ";
    // }
    for (int i = 0; i < trav.size(); i++)
    {
        cout << trav[i] << " ";
    }

    return 0;
}
// First iteration :

//     Size of the
//     queue(q.size()) is 1. Dequeue the front node(1) and
//     insert its value into the ans vector at the corresponding index based on the leftToRight flag.So,
//     ans[0] = 1. Enqueue the left and right children of the front node(2 and 3) if they exist.Direction 
//     is changed(leftToRight = !leftToRight), so it becomes false.The ans vector is now[1], and the direction is changed.

//                                                                                                                                                                                                  Second iteration :

//     Size of the queue is now 2. Dequeue the front nodes(2 and 3) and insert their values into the ans vector at the corresponding indices.Since leftToRight is false,
//     we insert in reverse order.So, ans[1] = 3 and ans[0] = 2. Enqueue the left and right children of nodes 2 and 3 if they exist.Direction 
//     is changed(leftToRight = !leftToRight), so it becomes true.The ans vector is now[2, 3], and the direction is changed.

//                                                                                                                                                                                                                                        Third iteration :

//     Size of the queue is now 4. Dequeue the front nodes(4, 5, 6) and insert their values into the ans vector at the corresponding indices.Since leftToRight is true,
//     we insert normally.So, ans[0] = 4, ans[1] = 5, and ans[2] = 6. Enqueue the left and right children of nodes 4, 5, and6 if they exist.Direction is 
//     changed(leftToRight = !leftToRight), so it becomes false.The ans vector is now[4, 5, 6], and the direction is changed.

//                                                                                                                                                                                                                                                    The final result vector is obtained by appending the values of ans in each iteration : [ 1, 2, 3, 4, 5, 6 ]
//                                                                                                                                                                                                                                                                                                                                               .Therefore,
//     the zigzag traversal of the given tree is[1, 3, 2, 4, 5, 6].