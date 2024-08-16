#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> stalls,int k,int mid,int n){

    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0;i<n;i++){

        if(stalls[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }

            lastPos = stalls[i];
        }
    }

    return false;
}


int aggressiveCows(vector<int> stalls,int k){

    sort(stalls.begin(),stalls.end());
    int start = 0;
    int n = stalls.size();
    int end = stalls[n-1];
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(isPossible(stalls,k,mid,n)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

int main()
{
    vector<int> stalls = {0,3,4,7,10,9};
    int cows = 4;

    int ans = aggressiveCows(stalls,cows);

    cout<<ans<<endl;
    
    return 0;
}