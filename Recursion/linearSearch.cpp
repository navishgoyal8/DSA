#include <iostream>
using namespace std;

bool linearSearch(int arr[],int n,int key){
    if(n == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        return linearSearch(arr+1,n-1,key);
    }
}


int main()
{   
    int arr[10] = {4,5,78,96,12,1,2,789,635,1000};
    int n = 10;
    int key;
    cout<<"Enter the key:";
    cin >> key;

    if(linearSearch(arr,n,key)){
        cout<<"TRUE!";
    }
    else{
        cout<<"FALSE!";
    }

    return 0;
}