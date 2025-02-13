// Cycle Detection using depth first search
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);

            if (cycleDetected)
            {
                return true;
            }
        }
        else if (visited[neighbour] && neighbour != parent)
        {
            // cycle present
            return true;
        }
    }

    return false;
}

// n  = number of nodes, m = number of edges
string CycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    // Define edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {2, 4}, {4, 5}, {5, 2}};

    // Number of nodes
    int n = 6;

    // Number of edges
    int m = edges.size();

    // // Display the edges
    // cout << "Edges of the graph:\n";
    // for (auto edge : edges) {
    //     cout << edge[0] << " -> " << edge[1] << endl;
    // }

    // Call CycleDetection function
    string result = CycleDetection(edges, n, m);

    // Output the result
    cout << "Does the graph contain a cycle? " << result << endl;

    return 0;
}