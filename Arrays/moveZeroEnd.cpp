#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    int arr1[] = {0,1,0,3,12};
    

    int value = 0;

    for(int i=0;i<5;i++){
        if(arr1[i] != 0){
            arr1[value] = arr1[i];
            value++;
        }
    }

    while(value < 5){
        arr1[value] = 0;
        value++;
    }

    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }

    return 0;
}