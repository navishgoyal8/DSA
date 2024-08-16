#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{   
    /*
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;

    sort(arr.begin(),arr.end());

    int i =0;
    while(i<arr.size()){
        int value = 0;
        int count = 1;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                count++;
                value++;
                if(value == 1){
                    ans.push_back(arr[i]);
                }
            }
        }
        i = i + count;
    }

    sort(ans.begin(),ans.end());

    for(auto i:ans){
        cout<<i<<" ";
    }
    */

    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;

    sort(arr.begin(),arr.end());

   for(int i=0;i<arr.size()-1;i++){
     if(arr[i] == arr[i+1]){
        ans.push_back(arr[i]);
        i++;
    }
   }

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}