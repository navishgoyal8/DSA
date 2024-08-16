#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leadersArray(vector<int> &arr){
    vector<int> ans;
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }

    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{   
    vector<int> arr = {16,17,4,3,5,2};
    vector<int> ans = leadersArray(arr);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}