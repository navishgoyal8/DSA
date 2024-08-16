#include <iostream>
#include <vector>
using namespace std;

int secondLargest(int arr[],int n)
{

    int largest = arr[0];
    int slargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }

        else if (largest > arr[i] && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }

    return slargest;
}

int main()
{   
    int arr[] = {1,40,5,2,36,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<secondLargest(arr,n)<<endl;


    return 0;
}