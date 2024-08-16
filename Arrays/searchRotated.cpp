#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    vector<int> arr = {7,8,1,2,3,4,5};

    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;

    int key = 7;

    while(start < end){
        
        if(arr[mid] == key){
            cout<<"TRUE!"<<endl;
            break;
        }

        if(arr[mid]>=arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }

        mid = start + (end - start)/2;
    }

    return 0;
}