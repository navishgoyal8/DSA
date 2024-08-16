#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr = {5,6,1,2,3,4};
    int n = arr.size();

    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }

    if (arr[n - 1] > arr[0])
    {
        count++;
    }

    if(count<=1){
        cout<<"YES!";
    }
    else{
        cout<<"NO!";
    }


    return 0;
}