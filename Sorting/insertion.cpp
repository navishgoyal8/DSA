#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 40, 5, 2, 36, 50};
    int n = arr.size();

    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;

        for(;j>=0;j--){

            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }

        arr[j+1] = temp;
    }

    for(auto i: arr){
        cout<<i<<" ";
    }

    return 0;
}