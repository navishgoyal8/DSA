#include <iostream>
using namespace std;

bool binarySearch(int arr[],int start,int end,int key){
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] > key){
            return binarySearch(arr,start,mid-1,key);
        }
        if(arr[mid] < key){
            return binarySearch(arr,mid+1,end,key);
        }

        if(arr[mid] == key){
            return true;
        }
    }


    return false;
}

int main()
{   
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int key = 0;
    
    if(binarySearch(arr,0,9,key)){
        cout<<"KEY IS PRESENT!";
    }
    else{
        cout<<"KEY IS ABSENT!";
    }

    return 0;
}