// Find Shortest Path in Undirected Graph Using Dijkstra Algorithm
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // prepare adj List
    unordered_map<int, list<pair<int, int>>> adjList;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // create distance array with infinite value
    vector<int> dist(vertices);
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = INT_MAX;
    }

    // create set
    set<pair<int, int>> st;

    // insert source node in set with distance 0
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top record
        auto Top = *(st.begin());
        int distTop = Top.first;
        int TopNode = Top.second;

        // remove topnode
        st.erase(st.begin());

        // neighbour find
        for (auto neighbour : adjList[TopNode])
        {
            // agar new entry distance less previous distance se
            if (distTop + neighbour.second < dist[neighbour.first])
            {
                // record find karo
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // recrod find ho gaya
                if (record != st.end())
                {
                    // delete karo previous distance from set
                    st.erase(record);
                }

                // distance array mainn upadate
                dist[neighbour.first] = distTop + neighbour.second;

                // new entry push karo set main
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()

{
    vector<vector<int>> V = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 4, 1}, {1, 3, 5}, {4, 3, 7}};
    int vertices = 5, Edges = 7;
    int source = 0;

    vector<int> Ans = dijkstra(V, vertices, Edges, source);

    for (int i = 0; i < Ans.size(); i++)
    {
        cout << Ans[i] << " ";
    }

    return 0;
}