// Cycle Detect In Directed Graph Using DFS
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &DfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    DfsVisited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour, visited, DfsVisited, adjList);
            if (cycleDetected)
            {
                return true;
            }
        }
        // visited ho or dfsvisited bhi  true ho toh cycle is present
        else if (DfsVisited[neighbour] && visited[neighbour])
        {
            return true;
        }
    }

    DfsVisited[node] = false;
    return false;
}

int DetectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    // call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, DfsVisited, adjList);

            if (cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}

int main()

{
    // Define edges of the graph
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 7}, {3, 8}, {8, 7}, {2, 4}, {4, 5}, {5, 6}, {6, 4}};
    // Number of nodes
    int n = 8;

    if (DetectCycleInDirectedGraph(n, edges))
    {
        cout << " the graph contain a cycle" << endl;
    }
    else
    {
        cout << " the graph does not contain a cycle" << endl;
    }

    return 0;
}