// Cycle Detection Algorithm Using BFS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// n = number of vertex
int DetectCycleInDirectedGraph(int n,vector<pair<int,int>> &edges)
{
    // build adj list
    unordered_map<int,list<int>> adjList;
    for(int i = 0 ; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }
    
    vector<int> indegree(n+1);
    // find all indegree
    for(auto i : adjList)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 degree wale push kar do
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    int count = 0;
    while (!q.empty())
    {
        int Front = q.front();
        q.pop();

        // count increment kar do
        count++;

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
    
    // agar count number of nodes ke equal ho toh cycle not present valid topological sort
    if(count == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()

{
     vector<pair<int,int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}};
    int n = 6;
    int cycleDetect = DetectCycleInDirectedGraph(n,edges);
    if(cycleDetect)
    {
        cout << "Cycle is Detected In Directed Graph"<<endl;
    }
    else
    {
        cout << "Cycle is Not Detected"<<endl;
    }

    return 0;
}



// Let's perform a dry run of the loop that calculates the indegree for each vertex:

// cpp
// Copy code
// vector<int> indegree(n+1); // Initialize the indegree vector

// // Loop over the adjacency list
// for(auto i : adjList)
// {
//     // i.first is the vertex
//     // i.second is the list of adjacent vertices

//     for(auto j : i.second)
//     {
//         // j is an adjacent vertex to i.first
//         indegree[j]++;
//     }
// }
// Given the edges vector:

// Copy code
// {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {4, 6}, {5, 6}}
// After the loop, the indegree vector will be updated as follows:

// For vertex 1, there are 2 edges going out from it (to vertices 2 and 3). So, indegree[2] and indegree[3] will be incremented.
// For vertex 2, there is 1 edge going out from it (to vertex 4). So, indegree[4] will be incremented.
// For vertex 3, there is 1 edge going out from it (to vertex 4). So, indegree[4] will be incremented.
// For vertex 4, there are 2 edges going out from it (to vertices 5 and 6). So, indegree[5] and indegree[6] will be incremented.
// For vertex 5, there is 1 edge going out from it (to vertex 6). So, indegree[6] will be incremented.
// For vertex 6, there are no edges going out from it, so its indegree remains 0.
// Therefore, the indegree vector will be:

// makefile
// Copy code
// Vertex:   1  2  3  4  5  6
// Indegree: 0  1  1  2  1  1