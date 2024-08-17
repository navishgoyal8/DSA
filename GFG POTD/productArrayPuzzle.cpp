#include <iostream>
#include <vector>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums)
{

    int n = nums.size();
    vector<long long int> ans(n, 1);

    long long int left = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = left;
        left *= nums[i];
    }

    long long right = 1;
    for (int i = n - 1; i >= 0; i--)
    {   
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;
}

int main()
{   
    vector<long long int> nums = {10, 3, 5, 6, 2};
    vector<long long int> ans = productExceptSelf(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}