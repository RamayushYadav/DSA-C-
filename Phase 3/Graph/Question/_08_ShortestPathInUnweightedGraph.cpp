// shortest Path In an Unweighted Graph
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &Edges, int src, int dest)
{
    // create adjlist
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < Edges.size(); i++)
    {
        int u = Edges[i].first;
        int v = Edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    visited[src] = true;

    while (!q.empty())
    {
        int Front = q.front();
        q.pop();

        for (auto neighbour : adjList[Front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = Front;
                q.push(neighbour);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest);

    while (currNode != src)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    // reverse the ans vector
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()

{
    vector<pair<int, int>> Edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {5, 8}, {6, 7}, {7, 8}};
    int src = 1, destination = 8;
    vector<int> ShortPath = shortestPath(Edges, src, destination);

    for (int i : ShortPath)
    {
        cout << i << " ";
    }

    return 0;
}