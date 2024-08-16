#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k)
{
    
    int n = arr.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int index = (i + n - k)%n;
        ans[index] = arr[i];
    }

    return ans;
}

int main()
{   
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> ans;
    ans = rotateArray(arr,1);

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}

