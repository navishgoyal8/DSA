#include <iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum = 0, maxi = LONG_MIN;
    int ansStart = -1;
    int ansEnd = -1;
    int start = 0;
    for(int i=0;i<n;i++){
        if(sum == 0){
            start = i;
        }
        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum<0){
            sum = 0;
        }
    }

    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    if(maxi < 0){
        return 0;
    }
    else{
        return maxi;
    }
}

int main()
{   
    int arr[] = {34,-50,42,14,-5,86};
    cout << maxSubarraySum(arr,6) << endl;

    return 0;
}