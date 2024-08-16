#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(int arr[],int n){
    int res = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            count++;
            res = max(res,count);
        }
        else{
            count = 0;
        }
    }

    return res;
}

int main()
{   
    int arr[] = {0,1,1,0,1,1,1,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findMaxConsecutiveOnes(arr,n);
    
    return 0;
}