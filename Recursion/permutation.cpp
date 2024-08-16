#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr,int index,vector<vector<int>> &ans){
    if(index >= arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int j=index;j<arr.size();j++){
        swap(arr[j],arr[index]);
        solve(arr,index+1,ans);
        
        //backtrack
        swap(arr[j],arr[index]);
    }
}

vector<vector<int>> permutation(vector<int> &arr){
    int index = 0;
    vector<vector<int>> ans;

    solve(arr,index,ans);

    return ans;
}

int main()
{   
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;

    ans = permutation(arr);

    for(int i=0;i<ans.size();i++){
        for(int j =0;j<ans[i].size();i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}