// Prims Algorithm to convert graph into minimum spanning tree
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
using namespace std;
vector<pair<pair<int,int>,int>>  calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>> &Graph)
{
    // prepare adjList
    unordered_map<int,list<pair<int,int>>> adjList;

    for (int i = 0; i < Graph.size(); i++)
    {
        int u = Graph[i].first.first;
        int v = Graph[i].first.second;
        int w = Graph[i].second;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for (int i = 0; i <= n ; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
    // let's start the algorithm
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        // step 1:
        // find the minimum node from key array
        for (int v = 0; v <= n; v++)
        {
            // node pahale  se true nahi hona chahiye or 
            //node ki value key array main choti honi chahiye minimum value se 
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        
        // step 2:
        // minimum value ko mst array main true mark kar do
        mst[u] = true;

        // step 3:
        // neighbour nodes ko travers karo
        for(auto neighbour : adjList[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;

            // agar neighour false mark hai or uska previous weight greater 
            // hai new weight se in key array
            if(mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;
    // tree 0 se start nahi ho raha or source node 1 jo ki 0 mark hai
    // isliye loop 2 se start karenge
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

// vector<pair<pair<int,int>,int>> calculatePrimsMST(int n, int m, vector<pair<pair<int,int>,int>> &Graph) {
//     // prepare adjList
//     unordered_map<int,list<pair<int,int>>> adjList;

//     for (int i = 0; i < Graph.size(); i++) {
//         int u = Graph[i].first.first;
//         int v = Graph[i].first.second;
//         int w = Graph[i].second;

//         adjList[u].push_back(make_pair(v,w));
//         adjList[v].push_back(make_pair(u,w));
//     }
    
//     vector<int> key(n);
//     vector<bool> mst(n);
//     vector<int> parent(n);

//     for (int i = 0; i < n; i++) {
//         key[i] = INT_MAX;
//         mst[i] = false;
//         parent[i] = -1;
//     }
    
//     // let's start the algorithm
//     key[0] = 0; // Start from vertex 0 in 0-based indexing
//     parent[0] = -1;

//     for (int i = 0; i < n - 1; i++) { // Use n - 1 iterations instead of n
//         int mini = INT_MAX;
//         int u = -1; // Initialize u with an invalid value
//         // step 1:
//         // find the minimum node from key array
//         for (int v = 0; v < n; v++) { // Iterate only through existing vertices
//             // node pahale se true nahi hona chahiye or 
//             // node ki value key array main choti honi chahiye minimum value se 
//             if (mst[v] == false && key[v] < mini) {
//                 u = v;
//                 mini = key[v];

//             }
//         }
        
//         // step 2:
//         // minimum value ko mst array main true mark kar do
//         mst[u] = true;

//         // step 3:
//         // neighbour nodes ko travers karo
//         for(auto neighbour : adjList[u]) {
//             int node = neighbour.first;
//             int weight = neighbour.second;

//             // agar neighbour false mark hai or uska previous weight greater 
//             // hai new weight se in key array
//             if (mst[node] == false && weight < key[node]) {
//                 parent[node] = u;
//                 key[node] = weight;
//             }
//         }
//     }

//     vector<pair<pair<int,int>,int>> result;
//     // Start from i = 1 for 1-based indexing
//     for (int i = 1; i < n - 1; i++) {
//         result.push_back({{parent[i], i}, key[i]});
//     }
//     return result;
// }
 
  
int main()

{
    int n = 6; // Number of vertices
    int m = 9; // Number of edges

    // Graph represented as edge list: (source, destination, weight)
    vector<pair<pair<int, int>, int>> Graph = {
        {{1, 2}, 4},
        {{1, 3}, 6},
        {{2, 3}, 8},
        {{2, 4}, 2},
        {{3, 4}, 3},
        {{3, 5}, 9},
        {{4, 5}, 5},
        {{4, 6}, 7},
        {{5, 6}, 1}
        // 0 based indexing
        // {{0,1},2},
        // {{1,2},3},
        // {{0,3},6},
        // {{1,3},8},
        // {{1,4},5},
        // {{2,4},7},
    };

    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, Graph);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto edge : result) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}