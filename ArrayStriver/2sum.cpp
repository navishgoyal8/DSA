#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{   
    // USING HASHMAPS
    //T.C => O(N * LOGN) (LOGN FOR FINDING THE ELEMENT IN THE MAP)
    // S.C => O(N)
    vector<int> arr = {1,2,3,4,5};
    int target = 8;
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        int diff = target - arr[i];
        if(mpp.find(diff) != mpp.end()){
            cout<<mpp[diff]<<" "<<i<<endl;
        }
        mpp[arr[i]] = i;
    }

    // USING TWO POINTERS (FOR THIS WE REQUIRE A SORTED ARRAY)
    //T.C => O(N)
    // S.C => O(1)
    int left = 0;
    int right = arr.size()-1;
    
    while(left < right){
        if(arr[left] + arr[right] == target){
            cout<<left<<" "<<right<<endl;
            break;
        }else if(arr[left] + arr[right] < target){
            left++;
        }else{
            right--;
        }
    }


    return 0;
}