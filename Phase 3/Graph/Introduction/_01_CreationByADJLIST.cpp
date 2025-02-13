// Creation Of Graph Using Adjacency List
// input ------------>
// Enter the number of nodes 5
// Enter the number of edges 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction -> 0 -> Undirected
        // direction -> 1 -> Directed

        // Creation An Edge From u to v
        adj[u].push_back(v);

        if (direction == 0)
        { // creating from v-u
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()

{
    int n;
    cout << "Enter the number of nodes ";
    cin >> n;
    int m;
    cout << "Enter the number of edges ";
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing the graph
    g.printAdjList();

    return 0;
}