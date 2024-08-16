// TIME COMPLEXICITY --> O(N)
// SPACE COMPLEXICITY ---> O(1)

#include <iostream>
using namespace std;
int main()
    
{
    int arr[] = {1,2,7,-4,3,2,-10,9,1};
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0;
    int ansStart = -1;
    int endStart = -1;

    for(int i=0;i<9;i++){

        if(sum == 0){
            start = i;
        }
        sum = sum + arr[i];
        
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            endStart = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }


    while(ansStart <= endStart){
        cout<<arr[ansStart]<<" ";
        ansStart++;
    }

    cout<<endl;
    cout<<maxi;

    return 0;
}