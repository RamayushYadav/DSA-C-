// Articulation Point In A Graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

int min(int a,int b)
{
    if(a < b)
    {
        return a;
    }

    return b;
}

void dfs(int node, int parent, vector<int> &low, vector<int> &disc, vector<int> &ap,
         unordered_map<int,bool> &vis, unordered_map<int, list<int>> &adjList, int &timer)
{
    // starting node visited is true
    vis[node] = true;
    // disc and low for each nodes are according to the timer values
    disc[node] = low[node] = timer++;
    int child = 0; 
    for(auto neighbour : adjList[node])
    {
        // agar neighbour is equal to parent then ignore this case
        if(neighbour == parent)
        { 
            // ignore and going to next iteration
            continue;
        }

        if(!vis[neighbour])
        {
            dfs(neighbour,node,low,disc,ap,vis,adjList,timer);
            // when return update low
            low[node] = min(low[node],low[neighbour]);
            // check articulation point when return
            if(low[neighbour] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }

        //back edges condition
        else
        {
            low[node] = min(low[node],disc[neighbour]);
        }
    }
    
    // ek or case banega jab ap ka parent -1 hoga
    if(parent == -1 && child > 1)
    {
        ap[node] = 1; 
    }
}

int main()

{
    // make edges for graph
    int n = 5; // number of vertices
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(1, 2));

    // preapre adjacency list of graph
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> low(n);
    vector<int> disc(n);
    unordered_map<int,bool> vis;
    // articulation point vector
    vector<int> ap(n, 0);

    // starting initialization of disc and low  array
    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, low, disc, ap, vis, adjList, timer);
        }
    }

    // print articulation points
    cout << "Articulatin Points Are --> ";
    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}