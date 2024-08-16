#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a,int n,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

vector<int> mergeHeaps(vector<int> &a,vector<int> &b,int n,int m){

    vector<int> ans;

    for(auto it: a){
        ans.push_back(it);
    }
    for(auto it: b){
        ans.push_back(it);
    }

    int size = ans.size();
    for(int i= size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }

    return ans;
}

int main()
{   
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};
    int n = a.size();
    int m = b.size();
    vector<int> ans = mergeHeaps(a,b,n,m);
    for(auto it: ans){
        cout<<it<<" ";
    }
    
    return 0;
}