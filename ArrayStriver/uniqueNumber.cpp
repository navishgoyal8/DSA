#include <iostream>
using namespace std;

int uniqueNumber(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        res = res^arr[i];
    }

    return res;
}

int main()
{   
    int arr[] = {2,3,4,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<uniqueNumber(arr,n);
    
    return 0;
}