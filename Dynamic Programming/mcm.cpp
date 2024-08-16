#include <iostream>
#include <vector>
using namespace std;

int solve(int i,int j,vector<int> arr, vector<vector<int>> dp){

    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;

    for(int k=i;k<j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);

        if(steps < mini){
            mini = steps;
        }
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> arr,int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));

    return solve(1,n-1,arr,dp);
}

int main()
{   
    vector<int> arr = {5,4,6,2,7};
    int n = arr.size();
    int ans = matrixMultiplication(arr,n);

    cout<<ans<<endl;

    return 0;
}