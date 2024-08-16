#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMax(vector<int> &v)
{
    int maxi = -1;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }

    return maxi;
}

int func(vector<int> v, int mid)
{
    int n = v.size();
    int totalHours = 0;
    for (int i = 0; i < n; i++)
    {
        double hour = (double)v[i] / (double)mid;
        totalHours += ceil(hour);
    }

    return totalHours;
}

int minimumRateToEatBananas(vector<int> v, int h)
{

    int low = 1;
    int high = findMax(v);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int total = func(v, mid);

        if (total <= h)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{   
    vector<int> v = {3,6,7,11};
    int h = 8;

    cout<<minimumRateToEatBananas(v,h);

    return 0;
}