#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// better approach
int longestConsecutiveElement(vector<int> &nums){
    if(nums.size() == 0){
        return 0;
    }

    sort(nums.begin(),nums.end());
    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0;i<n;i++){
        if(nums[i] - 1 == lastSmaller){
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if(lastSmaller != nums[i]){
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest,cnt);
    }

    return longest;
}

// optimal approach
int longestConsecutiveElementOptimal(vector<int> &a){
    int n = a.size();
    if(n == 0){
        return 0;
    }

    int longest = 1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt += 1;
                x += 1;
            }

            longest = max(longest,cnt);
        }
    }

    return longest;
}

int main()
{       
    vector<int> nums = {100,4,200,1,3,2};
    cout << longestConsecutiveElement(nums) << endl;
    cout << longestConsecutiveElementOptimal(nums) << endl;

    return 0;
}