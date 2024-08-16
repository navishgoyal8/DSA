#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 40, 5, 2, 36, 50};
    int n = arr.size();
    int flag = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

    for(auto i:arr){
        cout<<i<<" ";
    }


    return 0;
}