#include <iostream>
#include <vector>
using namespace std;

int partision(vector<int> &arr,int start,int end){

    int pivot = arr[start];

    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex],arr[start]);

    int i = start;
    int j = end;
    while(i < pivotIndex && j > pivotIndex){
        
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr,int start,int end){
    if(start >= end){
        return;
    }

    int pivot = partision(arr,start,end);

    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main()
{   
    vector<int> arr = {8,1,6,2,3,7,0,23,15,9,665};

    int start = 0;
    int end = arr.size()-1;

    quickSort(arr,start,end);

    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}