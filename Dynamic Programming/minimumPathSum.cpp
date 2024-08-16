#include <iostream>
#include <vector>
using namespace std;

int minimumPathSum(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){

    if(i == 0 && j == 0){
        return mat[i][j];
    }

    if(i < 0 || j < 0){
        return 1e9;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = mat[i][j] + minimumPathSum(i-1,j,mat,dp);
    int left = mat[i][j] + minimumPathSum(i,j-1,mat,dp);

    
    return  dp[i][j] = min(up,left); 

}

int main()
{   
    vector<vector<int>> mat = {{1,3,1},{1,5,1},{4,2,1}};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout << minimumPathSum(n-1,m-1,mat,dp);
    
    return 0;
}