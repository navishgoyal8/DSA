#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr1 = {1,2,3,0,0,0};
    int m = 3;

    vector<int> arr2 = {2,5,6};
    int n = arr2.size();

    vector<int> ans;

    int index1 = 0;
    int index2 = 0;

    while(index1 < m && index2 < n){
        
        if(arr1[index1]>arr2[index2]){
            ans.push_back(arr2[index2]);
            index2++;
        }
        else{
            ans.push_back(arr1[index1]);
            index1++;
        }
    }

    while(index1 < m){
        ans.push_back(arr1[index1]);
        index1++;
    }

    while (index2 < n)
    {
        ans.push_back(arr2[index2]);
        index2++;
    }

    int value = 0;
    for (auto i: ans)
    {
        arr1[value] = i;
        value++;
    }

    for(auto i: arr1){
        cout<<i<<" ";
    }

    



    return 0;
}