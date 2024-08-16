#include <iostream>
using namespace std;
int main()
{
    int n;
    int arr[100];

    cout<<"Enter the number of elements:";
    cin >> n;

    for(int i=0;i<n;i++){
        cout<<"Enter the element at index "<<i<<":";
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    int start = 0;
    int end = n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}