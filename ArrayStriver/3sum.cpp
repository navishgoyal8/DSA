#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Time complexity: O(n^2 * log(n))
// Space complexity: O(n) + O(n) 
vector<vector<int>> triplet(int n,vector<int> &num){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(num[i] + num[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> v = {num[i],num[j],third};
                sort(v.begin(),v.end());
                st.insert(v);
            }
                hashset.insert(num[j]);
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }

    return ans;
}

int main()
{   
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}