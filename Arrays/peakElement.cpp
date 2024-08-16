#include <iostream>
using namespace std;
int main()
{   
    cout<<"Hello"<<" "<<endl;
    int arr[] = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};

    int start = 0;
    int end = 9;

    int mid = start + (end - start)/2;

    while(start<end){
        
        if(arr[mid]<arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }

        mid = start + (end - start)/2;
    }

    cout<<mid<<" ";

    return 0;
}