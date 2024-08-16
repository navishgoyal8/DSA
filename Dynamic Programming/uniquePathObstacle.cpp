#include <iostream>
#include <vector>
using namespace std;

int mod = (int)1e9 + 7;

int f(int i, int j, vector<vector<int>> &mat,vector<vector<int>> &dp)
{   
    if(i>=0 && j>=0 && mat[i][j] == -1){
        return 0;
    }

    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = f(i - 1, j,mat,dp);
    int left = f(i, j - 1, mat,dp);

    return dp[i][j] = (up + left)%mod;
}

int uniquePathsObstacle(int m, int n,vector<vector<int>> &mat)  
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, mat,dp);
}

int main()
{
    return 0;
}