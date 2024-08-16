#include <iostream>
#include <vector>
using namespace std;

bool isSorted(int n,vector<int> &a){
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}

int main()
{   
    vector<int> a = {1,2,3,4,5,6};
    int n = a.size();
    cout<<isSorted(n,a)<<endl;
    
    return 0;
}