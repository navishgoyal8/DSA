#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> arr,int n){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while(start < end){

        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }

        mid = start + (end - start)/2;

    }

    return start;
}

int binarySearch(vector<int> arr,int n,int start,int end,int target){
   
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] > target){
            end = mid - 1;
        }
        if(arr[mid] < target){
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}


int main()
{   
    vector<int> arr = {3,1,2};
    int n = arr.size();

    int pivot = pivotIndex(arr,n);
    cout<<pivot<<endl;
    int key;
    cout<<"Enter the key:";
    cin >> key;
    int ans;

    if(key>=arr[pivot] && key<=arr[n-1]){
        ans = binarySearch(arr,n,pivot,n-1,key);
    }
    else{
        ans = binarySearch(arr,n,0,pivot-1,key);
    }

    cout<<ans<<endl;

    return 0;
}