// Breadth First Search (BFS)
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // adjList[u].push_back(v);
        adjList[u].insert(v);
        // adjList[v].push_back(u);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store fronNode into answer
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all components for graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int vertices = 7; // Number of vertices in the graph

    // Define the edges of the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {4, 6},
        {5, 6}};

    // Perform BFS and get the traversal result
    vector<int> traversalResult = BFS(vertices, edges);

    // Display the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : traversalResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}