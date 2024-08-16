#include <iostream>
#include <vector>
using namespace std;

//TOP-DOWN APPROACH
int fib1(int n,vector<int> dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fib1(n-1,dp) + fib1(n-2,dp); 
}

//BOTTOM-UP APPROACH
int fib2(int n){

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//SPACE OPTIMIZATION APPROACH
int fib3(int n){
    
    int first = 0;
    int second = 1;
    int current;

    for(int i=2;i<=n;i++){
        current = first + second;
        first = second;
        second = current;
    }

    if(n == 0){
        return 0;
    }
    else{
        return second;
    }
}


int main()
{   
    int n;
    cout<<"Enter the number:";
    cin >> n;

    vector<int> dp(n+1);

    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }

    cout<<fib1(n,dp)<<endl;
    cout<<fib2(n)<<endl;
    cout<<fib3(n)<<endl;
    
    return 0;
}