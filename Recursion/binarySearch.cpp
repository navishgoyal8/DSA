#include <iostream>
using namespace std;

bool binarySearch(int arr[],int start,int end,int key){

    if(start > end){
        return false;
    }
    
    int mid = start + (end - start)/2;
   
        if(arr[mid] == key){
            return true;
        }

        if(arr[mid] > key){
            return binarySearch(arr,start,mid-1,key);
        }
        if(arr[mid] < key){
            return binarySearch(arr,mid+1,end,key);
        }   
    }
    
    
int main()
{   
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    int key;
    cout<<"Enter the key:";
    cin >> key;

    if(binarySearch(arr,0,n-1,key)){
        cout<<"TRUE!";
    }
    else{
        cout<<"FALSE!";
    }


    return 0;
}