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

Node *buildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // push NULL as separator
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl; // enter
            if (!q.empty())
            {
                // queue still has some child
                // then again use separator
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

void mirrorTree(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main()

{
    Node *root = NULL;

    // Creating a tree
    root = buildBinaryTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    cout << endl;
    mirrorTree(root);

    levelOrderTraversal(root);

    return 0;
}