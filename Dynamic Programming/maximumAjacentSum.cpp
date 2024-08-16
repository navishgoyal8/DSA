#include <iostream>
#include <vector>
using namespace std;

int f(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
    {
        return nums[index];
    }

    if (index < 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int pick = nums[index] + f(index - 2, nums, dp);
    int notPick = 0 + f(index - 1, nums, dp);

    return dp[index] = max(pick, notPick);
}



int maxSumTabulation(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int notPick = dp[i-1];
        int pick = nums[i];
        if(i > 1){
            pick += dp[i-2];
        }

        dp[i] = max(pick,notPick);
    }

    return dp[n-1];
}

int maxSumSpaceOptimization(vector<int> nums)
{   
    int n = nums.size();
    int prev = nums[0]; 
    int prev2 = 0;     

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i]; 
        if (i > 1)
            pick += prev2; 

        int nonPick = 0 + prev; 

        int cur_i = max(pick, nonPick); 
        prev2 = prev;                   
        prev = cur_i;                   
    }

    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    vector<int> dp(n, -1);
    f(n - 1, nums, dp);
    return dp[n - 1];
}

int main()
{
    return 0;
}