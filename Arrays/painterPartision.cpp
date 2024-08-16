#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &boards,int n,int k,int mid){
    int painterCount = 1;
    int timeSum = 0;
    for(int i=0;i<n;i++){
        if(timeSum + boards[i] <= mid){
            timeSum = timeSum + boards[i];
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false;
            }

            timeSum = boards[i];
        }
    }

    return true;
}

int painterPartision(vector<int> &boards,int n,int k){

    if(k > n){
        return -1;
    }

    int start = 0;
    int sum  = 0;
    for(int i=0;i<n;i++){
        sum = sum + boards[i];
    }

    int ans = -1;
    int end = sum;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(isPossible(boards,n,k,mid)){
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
{       vector<int> boards = {2,1,5,6,2,3};
        int n = boards.size();
        int painters = 2;

        int ans = painterPartision(boards,n,painters);

        cout<<ans<<endl;

    return 0;
}