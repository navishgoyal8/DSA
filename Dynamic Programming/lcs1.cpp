#include <iostream>
#include <vector>
using namespace std;

void lcs(string a,string b){
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int length = dp[n][m];
    cout<<length<<endl;

    string ans = "";
    for(int i=0;i<length;i++){
        ans += "$";
    }
    int index = length-1;
    int i = n;
    int j = m;

    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans[index] = a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<ans<<endl;
}


int main()
{   
    string a = "abcbdab";
    string b = "bdcaba";

    lcs(a,b);

    return 0;
}