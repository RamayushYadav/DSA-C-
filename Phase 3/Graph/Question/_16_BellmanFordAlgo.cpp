// Bellman Ford Algorithm is Used to find the shorest distance in negative weighted graph
// also used for finding negative cycle in graph
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bellmonFord(int m, int n, vector<vector<int>> &Edges, int src, int dest)
{
    // preapre a distance array
    vector<int> dist(n + 1, INT_MAX);

    // src ki distance 0 mark kar denge
    dist[src] = 0;

    // n times loop chalayege
    for (int i = 1; i <= n; i++)
    {
        // traverse on edges
        for (int j = 0; j < m; j++)
        {
            int u = Edges[j][0];
            int v = Edges[j][1];
            int wt = Edges[j][2];
            if (dist[u] != INT_MAX && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    bool flag = false;

    for (int i = 1; i <= n; i++)
    {
        // traverse on edges
        for (int j = 0; j < m; j++)
        {
            int u = Edges[j][0];
            int v = Edges[j][1];
            int wt = Edges[j][2];
            if (dist[u] != INT_MAX && ((dist[u] + wt) < dist[v]))
            {
                flag = true;
            }
        }
    }

    if (flag == false)
    {
        return dist[dest];
    }

    // FLAG IS TRUE MEANS NEGATIVE CYCLE PRESNT
    return -1;
}

int main()

{
    vector<vector<int>> edges = {{1, 2, 2}, {2, 3, -1}, {1, 3, 2}};

    int src = 1;
    int dest = 3;

    int n = 3; // number of veritices
    int m = 3; // number of edges

    cout << "the shortest distance from " << src << " to " << dest << " is -> " << bellmonFord(m, n, edges, src, dest) << endl;

    return 0;
}