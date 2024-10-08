#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target){
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> v = {nums[i],nums[j],nums[k],(int)fourth};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }

                hashset.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//OPTIMAL APPROACH
vector<vector<int>> fourSumOptimal(vector<int> &nums,int target){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(j != i+1 && nums[j] == nums[j-1]){
                continue;
            }

            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(k < l && nums[l] == nums[l+1]){
                        l--;
                    }
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }

    return ans;
}


int main()
{
    return 0;
}