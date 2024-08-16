#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited)
{

    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, vector<string> ans, int x, int y, vector<vector<int>> visited, string path)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (isSafe(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{

    vector<string> ans;
    if (m[0][0 == 0])
    {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);

    return ans;
}

int main()
{
    vector<vector<int>> maze;
    int n = 4;

    vector<string> ans;

    ans = findPath(maze, n);

    return 0;
}