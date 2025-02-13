// Topological Sort Using Kanhz Algorithm
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &Edges, int V, int e)
{
    // create Adjacency List
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < e; i++)
    {
        int u = Edges[i][0];
        int v = Edges[i][1];

        adjList[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(V+1);

    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;

    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;

    while (!q.empty())
    {
        int Front = q.front();
        q.pop();

        // answer main store karlo
        ans.push_back(Front);

        // neighbour indegree update
        for (auto neighbour : adjList[Front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
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



// #include <iostream>
// #include <vector>
// #include <list>
// #include <unordered_map>
// #include <queue>
// using namespace std;

// vector<int> topologicalSort(vector<vector<int>> &Edges, int V, int e)
// {
//     // find maximum vertex number
//     int maxVertex = 0;
//     for (int i = 0; i < e; i++)
//     {
//         maxVertex = max(maxVertex, max(Edges[i][0], Edges[i][1]));
//     }

//     // create Adjacency List
//     unordered_map<int, list<int>> adjList;

//     for (int i = 0; i < e; i++)
//     {
//         int u = Edges[i][0];
//         int v = Edges[i][1];

//         adjList[u].push_back(v);
//     }

//     // find all indegrees
//     vector<int> indegree(maxVertex + 1);

//     for (auto i : adjList)
//     {
//         for (auto j : i.second)
//         {
//             indegree[j]++;
//         }
//     }

//     // 0 indegree walo ko push kardo
//     queue<int> q;

//     for (int i = 1; i <= maxVertex; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }

//     // dp bfs
//     vector<int> ans;

//     while (!q.empty())
//     {
//         int Front = q.front();
//         q.pop();

//         // answer main store karlo
//         ans.push_back(Front);

//         // neighbour indegree update
//         for (auto neighbour : adjList[Front])
//         {
//             indegree[neighbour]--;
//             if (indegree[neighbour] == 0)
//             {
//                 q.push(neighbour);
//             }
//         }
//     }

//     return ans;
// }

// int main()

// {
//     vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}};
//     int e = edges.size(); // number of edges
//     int V = 0; // number of vertices

//     for (auto edge : edges) {
//         V = max(V, max(edge[0], edge[1]));
//     }

//     vector<int> Ans = topologicalSort(edges, V, e);
//     for (int i = 0; i < Ans.size(); i++)
//     {
//         cout << Ans[i] << " ";
//     }

//     return 0;
// }
