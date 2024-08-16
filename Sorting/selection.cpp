#include <iostream>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }

        swap(arr[i],arr[mini]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{   
    int arr[] = {1,40,5,2,36,50};
    int ans = 0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
            ans = arr[j];
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort (arr,6);
    return 0;
}