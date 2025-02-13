// reverse an array using vector

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> V)
{
    int start = 0;
    int end = V.size() - 1;
    while (start <= end)
    {
        swap(V[start], V[end]);
        start++;
        end--;
    }
    return V;
}

vector<int> reverseatIndex(vector<int> V, int M)
{
    int start = M;
    int end = V.size() - 1;
    while (start <= end)
    {
        swap(V[start], V[end]);
        start++;
        end--;
    }
    return V;
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printIndexArray(vector<int> v, int index)
{
    for (int i = index; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    vector<int> ans = reverse(v);

    cout << "Printing reverse array -> ";
    print(ans);
    cout << endl;

    vector<int> Ans = reverseatIndex(v, 2);

    cout << "Printing reverse array at given index -> ";
    printIndexArray(Ans, 2);

    return 0;
}

