#include <iostream>
#include <queue>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
long long minCost(long long arr[],long long n){
    priority_queue<long long,vector<long long>,greater<long long>> minHeap;

    for(long long i=0;i<n;i++){
        minHeap.push(arr[i]);
    }

    long long cost = 0;

    while(minHeap.size() > 1){
        long long a = minHeap.top();
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();
        cost += a+b;
        minHeap.push(a+b);
    }

    return cost;
}

int main()
{   
    long long arr[] = {4,3,2,6};
    long long n = sizeof(arr)/sizeof(arr[0]);
    cout<<minCost(arr,n);

    return 0;
}