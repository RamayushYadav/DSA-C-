// Bridge In A Graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,unordered_map<int, list<int>> &adjList,unordered_map<int,bool> &visited)
{
    //śtarting main true hoga and timer ke according disc and low hoga
    visited[node] = true;
    disc[node] = low[node] = timer++;
    
    // neighbour traverse
    for(auto neighbour : adjList[node])
    {
        if(neighbour == parent)
        {
            // ignore
            continue;
        }
        
        if(!visited[neighbour])
        {
            dfs(neighbour,node,timer,disc,low,result,adjList,visited);

            //jab dfs call return hoga
            // low update
            low[node] = min(low[node],low[neighbour]);

            // check bridge
            if(low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        

        // agar visited hai toh back edge case check karenge
        else
        {
            low[node]= min(low[node],disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &Edges, int v, int e)
{
    // prepare adj List
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < Edges.size(); i++)
    {
        int u = Edges[i][0];
        int v = Edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;
    vector<int> disc(v);
    vector<int> low(v);

    unordered_map<int, bool> visited;

    // starting main visited is false , disc is -1 and low is -1
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        low[i] = -1;
        disc[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, disc, low, result, adjList, visited);
        }
    }

    return result;
}

int main() {
    // Define the edges of the graph
    vector<vector<int>> Edges = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {0, 3}, {3, 4}};

    int v = 5; // Number of vertices
    int e = Edges.size(); // Number of edges

    // // Define the edges of the graph
    // vector<vector<int>> Edges = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}};

    // int v = 6; // Number of vertices
    // int e = Edges.size(); // Number of edges


    // Call findBridges function
    vector<vector<int>> bridges = findBridges(Edges, v, e);

    // Display the bridges
    cout << "Bridges in the graph:" << endl;
    for (const auto& bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}

