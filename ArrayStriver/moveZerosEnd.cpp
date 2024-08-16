#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZerosEnd(int n,vector<int> a){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            temp.push_back(a[i]);
        }
    }

    int nz = temp.size();
    for(int i=0;i<nz;i++){
        a[i] = temp[i];
    }

    for(int i=nz;i<n;i++){
        a[i] = 0;
    }

    return a;   
}

vector<int> moveZerosEndOptimal(int n,vector<int> a){
    int j = -1;
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            j = i;
            break;
        }
    }

    // no non zero numbers
    if(j == -1){
        return a;
    }

    for(int i=j+1;i<n;i++){
        if(a[i] != 0){
            swap(a[i],a[j]);
            j++;
        }
    }

    return a;
}

int main()
{   
    vector<int> a = {1,0,2,0,3,0,4,0,5};
    int n = a.size();
    vector<int> res = moveZerosEnd(n,a);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;
    vector<int> res1 = moveZerosEndOptimal(n,a);
    for(int i=0;i<n;i++){
        cout<<res1[i]<<" ";
    }
    
    return 0;
}