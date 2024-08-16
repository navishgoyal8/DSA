#include <iostream>
using namespace std;

int minimumRotatedSort(int arr[],int n){
 
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[low] <= arr[high]){
            ans = min(ans,arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]){
            ans = min(ans,arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans,arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {4,5,6,-30,-20,2};
    int n = 6;
    cout<<minimumRotatedSort(arr,n);

    return 0;
}