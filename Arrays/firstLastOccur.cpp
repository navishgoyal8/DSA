#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &arr,int n,int target){
    int start = 0;
    int end = n-1;
    int ans = -1;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(arr[mid] == target){
            ans = mid;
            end = mid-1;
        }

        if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int lastOccurence(vector<int> &arr, int n, int target)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }

        if (arr[mid] > target)
        {
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
   vector<int> arr = {1,2,2,8,8,8,8,10};

    int first = firstOccurence(arr,arr.size(),8);
    int last = lastOccurence(arr,arr.size(),8);

    cout<<first<<" "<<last<<endl;

    return 0;
}
