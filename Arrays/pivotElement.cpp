#include <iostream>
#include <vector>

using namespace std;
int main()
{   
    vector<int> nums = {7,8,1,2,3,4,5};

    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }


    cout<<start<<" ";

    return 0;
}