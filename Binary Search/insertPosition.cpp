#include <iostream>
using namespace std;

int insertPosition(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int ans = n;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 8, 9, 10};
    int n = 19;
    int x = 7;
    cout << insertPosition(arr, n, x);

    return 0;
}