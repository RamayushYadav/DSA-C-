// Rate In A Maze
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, vector<vector<bool>> &visited, int n)
{
    if ((newx >= 0 && newx <= n - 1) && (newy >= 0 && newy <= n - 1) && visited[newx][newy] == 0 && arr[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // D L R U
    visited[x][y] = 1;
    // Down
    if (isSafe(x + 1, y, arr, visited, n))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, arr, visited, n))
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, arr, visited, n))
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, arr, visited, n))
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}

int main()

{
    vector<vector<int>> Maze = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = searchMaze(Maze, 4);
    // if (result.empty())
    // {
    //     cout << "No possible paths found!" << endl;
    // }
    // else
    // {
    //     cout << "Possible paths to reach the destination:" << endl;
    //     for (const string &path : result)
    //     {
    //         cout << path << endl;
    //     }
    // }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}