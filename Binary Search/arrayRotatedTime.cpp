#include <iostream>
using namespace std;

int minimumRotatedSort(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }    
            break;
        }

        if (arr[low] <= arr[mid])
        {   
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {   
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main()
{
    int arr[] = {4, 5,  -30, -20, 2};
    int n = 5;
    cout << minimumRotatedSort(arr, n);

    return 0;
}