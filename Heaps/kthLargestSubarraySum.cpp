#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// T.C => O(n^2*logn)
int getKthLargest(vector<int> &arr,int k){
    vector<int> sumStore;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(),sumStore.end());
    return sumStore[n-k];
}

int getKthLargestHeap(vector<int> &arr,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(minHeap.size() < k){
                minHeap.push(sum);
            }
            else{
                if(minHeap.top() < sum){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }   
        }
    }

    return minHeap.top();
}

int main()
{   

    return 0;
}