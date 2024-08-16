#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    vector<int> arr = {1,1,2,2,2,3,3};
    int i = 0;
    for(int j = 1; j < arr.size(); j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    for(int index = 0; index < i+1; index++){
        cout << arr[index] << " ";
    }


    return 0;
}