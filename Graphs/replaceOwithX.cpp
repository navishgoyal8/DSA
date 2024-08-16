#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    int delRow[] = {0, 1, 0, -1};
    int delCol[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, mat, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        if (!vis[0][i] && mat[0][i] == 'O')
        {
            dfs(0, i, mat, vis);
        }

        if (!vis[n - 1][i] && mat[n - 1][i] == 'O')
        {
            dfs(n - 1, i, mat, vis);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, mat, vis);
        }

        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, mat, vis);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

int main()
{
    return 0;
} 