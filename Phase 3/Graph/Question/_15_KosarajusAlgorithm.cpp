// Strongly Connected Components From Directed Graph
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adjList);
        }
    }

    // stack main push
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto neighbour : transpose[node])
    {
        if (!visited[neighbour])
        {

            revdfs(neighbour, visited, transpose);
        }
    }
}

int stronglyConnectedCompnents(int V, vector<vector<int>> &Edges)
{
    // prepare Adjacency List
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < Edges.size(); i++)
    {
        int u = Edges[i][0];
        int v = Edges[i][1];

        adjList[u].push_back(v);
    }

    // topo sort
    stack<int> st;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adjList);
        }
    }

    // create transpose of graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < V; i++)
    {
        // visited array starting main sabke liye false ho kyoki topo sort main ye update ho gaya tha
        visited[i] = false;
        for (auto neighbour : adjList[i])
        {
            transpose[neighbour].push_back(i);
        }
    }

    // dfs call using above ordering
    int count = 0;
    while (!st.empty())
    {
        int Top = st.top();
        st.pop();

        if (!visited[Top])
        {
            count++;
            revdfs(Top, visited, transpose);
        }
    }

    return count;
}

int main()

{
    vector<vector<int>> Edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    int V = 5;
 
    int SCC = stronglyConnectedCompnents(V, Edges);
    cout << "( " << SCC << " )"
         << "  Strongly Connected Components Are Exist In The Driected Graph" << endl;

    return 0;
}