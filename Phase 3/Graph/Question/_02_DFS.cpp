// Depth First Search (DFS)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1;

    // every connected node ke liye recursive call
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);  
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()

{
    // Sample graph with 6 vertices and 7 edges
    int V = 6;
    int E = 7;
    vector<vector<int>> Edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4},
        {4, 5},
        {2, 5},
        {1, 3}};

    vector<vector<int>> connectedComponents = depthFirstSearch(V, E, Edges);

    for (const auto &component : connectedComponents)
    {
        for (int vertex : component)
        {
            cout << vertex;
            if (vertex != component.back())
                cout << " -> ";
        }
        cout << endl;
    }
    return 0;
}