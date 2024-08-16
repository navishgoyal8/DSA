#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr,int n,int target){
    int start = 0;
    int end = n-1;
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == target){
            ans = mid;
            end = mid - 1;
        }

        if(arr[mid] > target){
            end = mid - 1;
        }
        if(arr[mid] < target)
        {
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return ans; 
}

int lastOccurence(vector<int> arr, int n, int target)
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
        if(arr[mid] < target)
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{       
    vector<int> arr = {1,2,3,8,8,8,8,8,10,11,11,23,32,345};
    int n = arr.size();
    int target;
    cout<<"Enter the target:";
    cin >> target;

    int first = firstOccurence(arr,n,target);
    int last = lastOccurence(arr, n, target);
    cout<<first<<" "<<last<<endl;;


    int total = last - first + 1;

    cout<<total<<endl;

    return 0;
}