#include <iostream>
#include <vector>
using namespace std;

// T.C => O(4*n)*3
// S.C => O(4*n) + O(N)
int f(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0;task < 3;task++){
            if(task != last){
                maxi = max(maxi,points[0][task]);
            }
        }

        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }
     
    int maxi = 0;

    for(int task = 0;task < 3;task++){
        if(task != last){
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }

    return dp[day][last] = maxi;
}

int main()
{   
    int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(3));
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return 0;
}