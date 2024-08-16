#include <iostream>
#include <vector>
using namespace std;

int getFloor(vector<int> &a, int n, int x)
{

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] <= x)
        {
            ans = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int getCeil(vector<int> &a, int n, int x)
{

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] >= x)
        {
            ans = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{

    int floor = getFloor(a, n, x);
    int ceil = getCeil(a, n, x);

    pair<int, int> p;
    p.first = floor;
    p.second = ceil;

    return p;
}

int main()
{   
    vector<int> a = {1, 2, 8, 10, 10, 12, 19};
    int n = 7;
    int x = 11;
    pair<int, int> p = getFloorAndCeil(a, n, x);
    cout << p.first << " " << p.second;

    return 0;
}