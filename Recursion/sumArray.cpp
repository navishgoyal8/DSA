#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }

    return arr[0] + sum(arr + 1, n - 1);
}

int main()
{
    int arr[] = {1, 2, 2, 5, 6, 4, 3, 4, 5, 6, 7, 8, 9, 10};

    int ans = sum(arr, 14);

    cout << ans << endl;

    return 0;
}