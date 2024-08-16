#include <iostream>
#include <vector>
using namespace std;

bool isSorted(int arr[],int n){


    if(n == 0 || n == 1)
    {
        return true;
    }

    if(arr[1] >= arr[0])
    {
         return isSorted(arr+1,n-1);
    }
    else
    {
        return false;
    }

}

int main()
{   
    int arr[] = {1,4,5,6,9,10,12,15};

    int n = 8;

    if(isSorted(arr,n)){
        cout<<"TRUE!"<<endl;
    }
    else{
        cout<<"FALSE!"<<endl;
    }

    return 0;
}