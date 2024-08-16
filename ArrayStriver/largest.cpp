#include <iostream>
using namespace std;
int main()
{   
    int arr[] = {1,40,5,2,36,50};
    int maxi = arr[0];

    for(int i=0;i<6;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    
    cout<<maxi<<endl;

    return 0;
}