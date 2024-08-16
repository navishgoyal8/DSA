#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr,int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{   
    vector<int> arr = {0,1,2,0,1,2};
    sort012(arr,arr.size());
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}