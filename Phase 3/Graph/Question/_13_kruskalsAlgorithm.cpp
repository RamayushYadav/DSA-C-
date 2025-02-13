// Kruskal's Algorithm
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// comparator
bool cmp(vector<int> &a, vector<int> &b)
{   // weight third coulmn main hai matlab second index
    // according to the weight list is sort
    return a[2] < b[2];
}
void makeSet(vector<int> &rank, vector<int> &parent, int n)
{
    for (int i = 0; i < n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node)
{
    // base case (topmost parent)
    if (parent[node] == node)
    {
        return node;
    }

    // union && compression to decreae time and depth
    return parent[node] = findParent(parent, parent[node]);
}

void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    // u ki rank v se kam hai v hoga u ka parent
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }

    // v ki rank u se kam hai u hoga v ka parent
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }

    //  (rank[u] == rank[v])
    // rank agar equal hai toh koi bhi parent ho sakta hai
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &Edges, int n)
{
    // sort the edges vector
    // according to the weight list is sort
    sort(Edges.begin(), Edges.end(), cmp);

    vector<int> parent(n+1);
    vector<int> rank(n+1);
    // make the rank and parent array
    makeSet(rank, parent, n);

    int minWeight = 0;

    for (int i = 0; i < Edges.size(); i++)
    {
        int u = findParent(parent, Edges[i][0]);
        int v = findParent(parent, Edges[i][1]);
        int weight = Edges[i][2];

        if (u != v)
        {
            minWeight += weight;
            UnionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main()

{
    vector<vector<int>> Edges = {
        {1, 4, 1},
        {1, 5, 4},
        {1, 2, 2},
        {2, 4, 3},
        {2, 3, 3},
        {2, 6, 7},
        {3, 6, 8},
        {3, 4, 5},
        {4, 5, 9}};
    int n = 6;
    int minimumtree = minimumSpanningTree(Edges, n);

    cout << minimumtree << endl;

    return 0;
}
