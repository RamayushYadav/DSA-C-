// Topological Sort Using DFS
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList)
{
    visited[node] = 1;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, st, adjList);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)
{
    // build adj list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // call dfs topological sort util function for all components
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 1; i < V; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, st, adjList);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()

{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}};
    int V = 6, e = 7;
    vector<int> Ans = topologicalSort(edges, V, e);
    for (int i = 0; i < Ans.size(); i++)
    {
        cout << Ans[i] << " ";
    }

    return 0;
}