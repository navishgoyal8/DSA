#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight,vector<int> &value,int index,int capacity,vector<vector<int>> dp){
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

        int include = 0;
        if(weight[index] <= capacity){
            include = value[index] + solve(weight,value,index-1,capacity - weight[index],dp);
        }

        int exclude = solve(weight,value,index-1,capacity,dp);

        int ans = max(include,exclude);

        return dp[index][capacity] = ans;
    }

int dpTab(vector<int> weight,vector<int> value,int n,int capacity,vector<int> ans){
    
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    for(int w = weight[0];w <= capacity;w++){
        if(weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include = 0;
            if(weight[index] <= w){
                ans.push_back(weight[index]);
                include = value[index] + dp[index-1][w-weight[index]];
                
            }

            int exclude = dp[index-1][w];

            dp[index][w] = max(exclude,include);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return dp[n-1][capacity];

}


int knapsack(vector<int> weight,vector<int> value,int n,int maxWeight){

    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    // return solve(weight,value,n-1,maxWeight,dp);
    vector<int> ans;
    return dpTab(weight,value,n,maxWeight,ans);
}

int main()
{   

    vector<int> weight = {2,3,4};
    vector<int> values = {1,2,5};
    int maxWeight = 6;

    int ans = knapsack(weight,values,weight.size(),maxWeight);

    cout<<ans<<endl;

    return 0;
}