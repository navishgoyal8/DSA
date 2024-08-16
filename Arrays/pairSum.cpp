#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int arr[5] = {2,-6,2,5,2};
    vector<vector<int>> ans;
    
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
        if(arr[i]+arr[j] == 4){
            if(arr[i]>=arr[j]){
                ans.push_back({arr[j],arr[i]});
            }
            else{
                ans.push_back({arr[i], arr[j]});
            }
            
        }
        }
    }

    sort(ans.begin(),ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}