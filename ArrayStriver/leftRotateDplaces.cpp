#include <iostream>
#include <algorithm>
using namespace std;

void leftRotate(int *arr,int n,int d){
    d = d%n;
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i] = arr[i];
    }

   for(int i=d;i<n;i++){
       arr[i-d] = temp[i];
   }

   for(int i=n-d;i<n;i++){
       arr[i] = temp[i - (n-d)];
   }
}

void leftRotateOptimal(int *arr,int n,int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}

int main()
{   
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    leftRotateOptimal(arr,n,d);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}