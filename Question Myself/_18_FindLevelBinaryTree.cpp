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

int find_level(Node *root, vector<int> &V)
{
    queue<Node *> q;
   
    // V.push_back(root->data);
    q.push(root);
    int level = -1;
    int maxi ;
    while (!q.empty())
    {
        int size = q.size();
        maxi = -1;
        while (size)
        {
            Node *temp = q.front();
            q.pop();
            maxi = max(maxi,temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }

            size--;
        }
        V.push_back(maxi);
        level++;
    }
    return level;
}

void find_maximum(Node *root, vector<int> &V)
{
    queue<Node *> q;
    q.push(root);
    int level = -1;
    int maxi ;
    while (!q.empty())
    {
        int size = q.size();
        maxi = -1;
        while (size)
        {
            Node *temp = q.front();
            q.pop();
            maxi = max(maxi,temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            
            size--;
        }
        V.push_back(maxi);
        level++;
    }
    
}

int main()

{
    Node *root = NULL;

    // Creating a tree
    root = buildBinaryTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    cout << endl;
    vector<int> vec;
    // levelOrderTraversal(root,vec);


    // int level = find_level(root,vec);
    // cout << "tree level is " << level << endl;
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }
    // cout << endl;
    int level = FlevelOrderTraversal(root);
    cout << level<<endl;
    return 0;
}