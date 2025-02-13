// #include <iostream>
// #include <vector>
// using namespace std;

// bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited, int x, int y, int n)
// {
//     if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void solve(vector<vector<int>> &m, vector<vector<int>> visited, int x, int y, int n, string path, vector<string> &ans)
// {
//     if (x == n - 1 && y == n - 1)
//     {
//         ans.push_back(path);
//         return;
//     }
//     visited[x][y] = 1;
//     // Down
//     int newx = x + 1;
//     int newy = y;
//     if (isSafe(m, visited, newx, newy, n))
//     {
//         path.push_back('D');
//         solve(m, visited, newx, newy, n, path, ans);
//         path.pop_back();
//     }
//     // UP
//     newx = x - 1;
//     newy = y;
//     if (isSafe(m, visited, newx, newy, n))
//     {
//         path.push_back('U');
//         solve(m, visited, newx, newy, n, path, ans);
//         path.pop_back();
//     }
//     // left
//     newx = x;
//     newy = y - 1;
//     if (isSafe(m, visited, newx, newy, n))
//     {
//         path.push_back('L');
//         solve(m, visited, newx, newy, n, path, ans);
//         path.pop_back();
//     }
//     // right
//     newx = x;
//     newy = y + 1;
//     if (isSafe(m, visited, newx, newy, n))
//     {
//         path.push_back('R');
//         solve(m, visited, newx, newy, n, path, ans);
//         path.pop_back();
//     }
//     visited[x][y] = 0;
// }

// vector<string> findPath(vector<vector<int>> &m, int n)
// {
//     vector<vector<int>> visited = m;
//     vector<string> ans;
//     if (m[0][0] == 0)
//     {
//         return ans;
//     }

//     string path;
//     int srcx = 0;
//     int srcy = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             visited[i][j] = 0;
//         }
//     }

//     solve(m, visited, srcx, srcy, n, path, ans);

//     return ans;
// }

// int main()
// {
//     int n;
//     cout << "Enter the size of the maze: ";
//     cin >> n;

//     vector<vector<int>> maze(n, vector<int>(n, 0));

//     cout << "Enter the maze elements (0/1):\n";
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             cin >> maze[i][j];
//         }
//     }

//     vector<string> result = findPath(maze, n);

//     if (result.empty())
//     {
//         cout << "No possible paths found!" << endl;
//     }
//     else
//     {
//         cout << "Possible paths to reach the destination:" << endl;
//         for (const string &path : result)
//         {
//             cout << path << endl;
//         }
//     }

//     return 0;
// }

/*
#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) {

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}


bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;

}

void removeLoop(Node* head) {

    if( head == NULL)
        return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;

}


int main() {

    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    //print(head);

    insertAtTail(tail, 12);

    //print(head);

    insertAtTail(tail, 15);
    //print(head);

    insertAtPosition(tail,head, 4, 22);
    //print(head);

    //cout << "head " << head -> data << endl;
    //cout << "tail " << tail -> data << endl;

    //deleteNode(4, head);


    tail -> next = head ->next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    //print(head);

    if(floydDetectLoop(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    Node* loop = getStartingNode(head);

    cout << "loop starts at " << loop -> data  << endl;

    removeLoop(head);
    print(head);


    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }



    return 0;
}

*/

// #include <iostream>
// using namespace std;

// void display(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void Sort(int arr[], int n)
// {
//     int zerocount = 0;
//     int onecount = 0;
//     int twocount = 0;
//     int i = 0;
//     // store the counts
//     while (i < n)
//     {
//         if (arr[i] == 0)
//         {
//             zerocount++;
//             i++;
//         }
//         else if (arr[i] == 1)
//         {
//             onecount++;
//             i++;
//         }
//         else if (arr[i] == 2)
//         {
//             twocount++;
//             i++;
//         }
//     }

//     int j = 0;
//     // store the elements

//     // Update the array elements based on counts
//     // while (zerocount > 0)
//     // {
//     //     arr[j] = 0;
//     //     j++;
//     //     zerocount--;
//     // }

//     // while (onecount > 0)
//     // {
//     //     arr[j] = 1;
//     //     j++;
//     //     onecount--;
//     // }

//     // while (twocount > 0)
//     // {
//     //     arr[j] = 2;
//     //     j++;
//     //     twocount--;
//     // }
//     while (j < n)
//     {
//         if (zerocount != 0)
//         {
//             arr[j] = 0;
//             j++;
//             zerocount--;
//         }
//         else if (onecount != 0)
//         {
//             arr[j] = 1;
//             j++;
//             onecount--;
//         }
//         else if (twocount != 0)
//         {
//             arr[j] = 2;
//             j++;
//             twocount--;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {1, 0, 2, 1, 2, 0};

//     display(arr, 6);

//     Sort(arr, 6);

//     display(arr, 6);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//         this->prev = NULL;
//     }

//     ~Node()
//     {
//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "Memory free for node with data " << value << endl;
//     }
// };

// void InsertAtHead(Node *&head, int d)
// {
//     Node *temp = new Node(d);
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
// }

// InsertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     temp->prev = tail;
//     tail = temp;
// }

// void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
// {
//     if (position == 1)
//     {
//         InsertAtHead(head, d);
//         return;
//     }

//     Node *temp = head;
//     int count = 1;
//     while (count < position - 1)
//     {
//         temp = temp->next;
//         count++;
//     }

//     if (temp->next == NULL)
//     {
//         InsertAtTail(tail, d);
//         return;
//     }

//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next->prev = nodeToInsert;
//     temp->next = nodeToInsert;
//     nodeToInsert->prev = temp;
// }

// void deleteNode(Node *&head, int position)
// {
//     if (position == 1)
//     {
//         Node *temp = head;
//         temp->next->prev = NULL;
//         head = temp->next;
//         temp->next = NULL;
//         delete temp;
//     }

//     else
//     {
//         Node *curr = head;
//         Node *previous = NULL;

//         int count = 1;
//         while (count < position)
//         {
//             previous = curr;
//             curr = curr->next;
//             count++;
//         }
//         curr->prev = NULL;
//         previous->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//     }
// }

// void display(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;

//     InsertAtHead(head, 9);
//     display(head);
//     InsertAtTail(tail, 11);
//     display(head);
//     InsertAtTail(tail, 12);
//     display(head);
//     InsertAtPosition(head, tail, 2, 55);
//     display(head);
//     InsertAtPosition(head, tail, 2, 16);
//     display(head);

//     deleteNode(head, 1);
//     display(head);
//     return 0;
// }
// #include<iostream>
// #include<queue>
// #include<climits>
// using namespace std;

// class Node

// {
//     public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Node *buildBST(Node *root,int d)
// {
//     if(root == NULL)
//     {
//         root = new Node(d);
//         return root;
//     }

//     if(d > root->data)
//     {
//         root->right = buildBST(root->right,d);
//     }
//     else
//     {
//         root->left = buildBST(root->left,d);
//     }
//     return root;
// }

// void takeInput(Node *&root)
// {
//     int data;
//     cin >> data;

//     while(data != -1)
//     {
//         root = buildBST(root,data);
//         cin >> data;
//      }

// }

// bool isBST(Node *root,int min,int max)
// {
//     if(root == NULL)
//     {
//         return true;
//     }

//     if(root->data > min && root->data < max)
//     {
//         bool left = isBST(root->left,min,root->data);
//         bool right = isBST(root->right,root->data,max);

//         return left && right;
//     }

//     return false;
// }

// bool ValidateBST(Node *root)
// {
//     return isBST(root,INT_MIN,INT_MAX);
// }

// int solve(Node *root,int &i,int k)
// {
//     if(root == NULL)
//     {
//         return -1;
//     }

//     int left = solve(root->left,i,k);
//     if(left != -1)
//     {
//         return left;
//     }

//     i++;
//     if(i == k)
//     {
//         return root->data;
//     }

//     return solve(root->right,i,k);
// }

// int kthSmallestElement(Node *root, int k)
// {
//     int i = 0;
//     int ans = solve(root, i, k);
//     return ans;
// }

// void levelOrderTraversal(Node *root)
// {
//    queue<Node*> q;
//    q.push(root);
//    q.push(NULL);

//    while(!q.empty())
//    {
//         Node *temp = q.front();
//         q.pop();
//         if(temp == NULL)
//         {
//             cout << endl;
//             if(!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if(temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if(temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//    }
// }

// pair<int,int> predecessorsuccessor(Node *root,int key)
// {
//     Node *temp = root;
//     int pred = -1;
//     int succ = -1;

//     while(temp->data != key)
//     {
//         if(temp->data > key)
//         {
//             succ = temp->data;
//             temp =temp->left;
//         }
//         else
//         {
//             pred = temp->data;
//             temp = temp->right;
//         }
//     }

//     Node *leftTree = temp->left;
//     while(leftTree != NULL)
//     {
//         pred = leftTree->data;
//         leftTree = leftTree->right;
//     }

//     Node *rightTree = temp->right;
//     while(rightTree != NULL)
//     {
//         succ = rightTree->data;
//         rightTree = rightTree->left;
//     }

//     pair<int,int> ans = make_pair(pred,succ);
//     return ans;
// }

// void preOrder(Node *root)
// {
//     // base case
//     if(root == NULL)
//     {
//         return;
//     }

//     cout << root->data << " ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void postOrder(Node *root)
// {
//     // base case
//     if(root == NULL)
//     {
//         return;
//     }

//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data << " ";
// }

// void inOrder(Node *root)
// {
//     if(root == NULL)
//     {
//         return;
//     }

//     inOrder(root->left);
//     cout << root->data << " ";
//     inOrder(root->right);
// }

// int main()

// {
//     Node *root = NULL;

//     takeInput(root);
// levelOrderTraversal(root);

// inOrder(root);
// cout << endl;
// preOrder(root);
// cout << endl;
// postOrder(root);
// cout << endl;
// if(ValidateBST(root))
// {
//     cout << "TRUE"<< endl;
// }
// else
// {
//     cout << "FALSE"<<endl;
// }

// int k = 3;
// cout << "The "<<k<<"rd smallest element is "<<kthSmallestElement(root,k)<<endl;

// pair<int,int> bhang = predecessorsuccessor(root,30);
// cout << bhang.first << " "<< bhang.second << endl;
//     return 0;
// }

// void preOrder(Node *root, vector<int> &pre)
// {
//    if (root == NULL)
//     {
//         return;
//     }

//     root->data = pre.front();
//     pre.erase(pre.begin());

//     preOrder(root->left, pre);
//     preOrder(root->right, pre);
// }
// // Basic operation in binary tree(implementation of binary tree)
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// #include <iostream>
// #include <climits>
// #include <vector>
// #include <list>
// #include <unordered_map>
// using namespace std;

// vector<pair<pair<int, int>, int>> calculatePrimsAlgorithm(int n, int m, vector<pair<pair<int, int>, int>> &graph)
// {
//     unordered_map<int, list<pair<int, int>>> adjList;
//     for (int i = 0; i < graph.size(); i++)
//     {
//         int u = graph[i].first.first;
//         int v = graph[i].first.second;
//         int w = graph[i].second;

//         adjList[u].push_back(make_pair(v, w));
//         adjList[v].push_back(make_pair(u, w));
//     }

//     vector<int> key(n);
//     vector<bool> mst(n);
//     vector<int> parent(n);

//     for (int i = 0; i < n; i++)
//     {
//         key[i] = INT_MAX;
//         mst[i] = false;
//         parent[i] = -1;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int i = 0; i < n; i++)
//     {
//         int mini = INT_MAX;
//         int u;

//         for (int v = 0; v < n - 1; v++)
//         {
//             if (mst[v] == false && key[v] < mini)
//             {
//                 u = v;
//                 mini = key[v];
//             }
//         }

//         mst[u] = true;

//         for (auto neighbour : adjList[u])
//         {
//             int node = neighbour.first;
//             int weight = neighbour.second;

//             if (mst[node] == false && key[node] > weight)
//             {
//                 key[node] = weight;
//                 parent[node] = u;
//             }
//         }
//     }
//     vector<pair<pair<int, int>, int>> result;
//     for (int i = 1; i < n; i++)
//     {
//         result.push_back({{parent[i],i},key[i]});
//     }

//     return result;
// }

// int main()

// {
//     int n = 5; // Number of vertices
//     int m = 6; // Number of edges

//     // Graph represented as edge list: (source, destination, weight)
//     vector<pair<pair<int, int>, int>> Graph = {
//         {{0,1},2},
//         {{1,2},3},
//         {{0,3},6},
//         {{1,3},8},
//         {{1,4},5},
//         {{2,4},7}
//     };

//     vector<pair<pair<int, int>, int>> result = calculatePrimsAlgorithm(n, m, Graph);

//     cout << "Edges in the Minimum Spanning Tree:" << endl;
//     for (auto edge : result) {
//         cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
//     }

//     return 0;
// }
// #include <iostream>
// #include <queue>
// #include<vector>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// void findi(int left, Node *root, vector<vector<int>> &V)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if(left == 0)
//     {
//     V.push_back(root->data);
//     }
    

//     findi(left, root->right, V);
//     findi(left + 1, root->left, V);
// }

// vector<int> Diagonal(Node *root)
// {
//     vector<vector<int>> V;
//     vector<int> ans;
//     findi(0, root, V);
//     for (int i = 0; i < V.size(); i++)
//     {
//         for (int j = 0; j < V.size(); j++)
//         {
//             ans.push_back(V[i][j]);
//         }
//     }

//     return ans;
// }

// Node *buildBinaryTree(Node *root)
// {
//     int data;
//     cout << "Enter the data ";
//     cin >> data;

//     root = new Node(data);

//     if (data == -1)
//     {
//         return NULL;
//     }

//     cout << "Enter the data for inserting in left of " << data << endl;
//     root->left = buildBinaryTree(root->left);

//     cout << "Enter the data for inserting in right of " << data << endl;
//     root->right = buildBinaryTree(root->right);

//     return root;
// }

// int main()

// {
//     Node *root = NULL;

//     // Creating a tree
//     root = buildBinaryTree(root);
//     // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
//     vector<int> Di = Diagonal(root);
//     for (int i = 0; i < Di.size(); i++)
//     {
//         cout << Di[i] << " ";
//     }
    
//     return 0;
// }
