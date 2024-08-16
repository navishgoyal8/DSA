#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[],int n,int k){
    priority_queue<int> maxHeap;
    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(maxHeap.top() > arr[i]){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    int ans = maxHeap.top();
    return ans;
}


int main()
{   
    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<kthSmallestElement(arr,n,k);
    
    return 0;
}