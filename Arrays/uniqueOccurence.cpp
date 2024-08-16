#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ans;

    sort(arr.begin(), arr.end());

    int count = 1;
    int i = 0;

    while (i < arr.size())
    {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        ans.push_back(count);
        i = i + count;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] == ans[i + 1])
        {
            return false;
        }
    }

    return true;
    

    return 0;
}