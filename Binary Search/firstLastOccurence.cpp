#include <iostream>
#include <vector>
using namespace std;

int getLowerBound(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int getUpperBound(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> ans;
    if (nums.size() == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    int n = nums.size();
    int lb = getLowerBound(nums, target);
    if (lb == n || nums[lb] != target)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    int ub = getUpperBound(nums, target);
    ans.push_back(lb);
    ans.push_back(ub - 1);
    return ans;
}

int main()
{   
    vector<int> nums = {5,7,7,7,8,10};
    int target = 7;
    vector<int> ans = searchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}