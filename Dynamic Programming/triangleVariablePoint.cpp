#include <iostream>
#include <vector>
using namespace std;

int  f(int i,int j,vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
    if(i == n-1){
        return triangle[n-1][j];
    }

    int d = triangle[i][j] + f(i+1,j,triangle,n,dp);
    int r = triangle[i][j] + f(i+1,j+1,triangle,n,dp);

    return min(d,r);
}

int minimumPath(vector<vector<int>> &triangle,int n){

    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}

int main()
{
    return 0;
}