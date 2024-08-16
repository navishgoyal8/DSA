#include <iostream>
using namespace std;

int upperBound(int arr[],int n,int x){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int ans = n;

    while(start <= end){

        if(arr[mid] > x){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int main()
{   
    int arr[] = {1,2,3,3,3,3,3,3,3,3,3,3,3,4,5,6,8,9,10};
    int n = 20;
    int x = 3;
    cout<<upperBound(arr,n,x);
    
    return 0;
}