#include <iostream>
#include <vector>
using namespace std;

//TOP-DOWN APPROACH
int fTop(int index, vector<int> &dp)
{
    if (index <= 1)
    {
        return 1;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    return dp[index] = fTop(index - 1, dp) + fTop(index - 2, dp);
}

//BOTTOM - UP
int fBottom(int index,vector<int> &dp){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=index;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[index];
}

//SPACE OPTIMIZATION
int fSpace(int index){
    int first = 1;
    int second = 1;
    int current;

    for(int i=2;i<=index;i++){
        current = first + second;
        first = second;
        second = current;
    }

    return second;
}

int main()
{   
    int n;
    cout<<"Enter the number:";
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fTop(n,dp) << endl;
    cout << fBottom(n,dp) << endl;
    cout << fSpace(n) << endl;

    return 0;
}