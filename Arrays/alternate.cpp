#include <iostream>
using namespace std;
int main()
{   
    int arr[] = {1,2,3,4,5};
    int start = 0;
    int end = 1;

    while(end<=4){
        swap(arr[start],arr[end]);
        start = start + 2;
        end = end + 2;
    }

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}