#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {0,1,2,1,2,1,2};

    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0;

    for(int i=0;i<7;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        if (arr[i] == 1)
        {
            oneCount++;
        }
        if (arr[i] == 2)
        {
            twoCount++;
        }
    }

    int index = 0;
    while(zeroCount--){
        arr[index++] = 0;
    }
    while (oneCount--)
    {
        arr[index++] = 1;
    }
    while (twoCount--)
    {
        arr[index++] = 2;
    }

    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}