#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &a,int N){
    int xor1 = 0;
    int xor2 = 0;
    int n = N-1;
    for(int i=0;i<n;i++){
        xor2 = xor2^a[i];
        xor1 = xor1^(i+1);
    }

    xor1 = xor1 ^ N;

    return xor1^xor2;
}

int main()
{   
    vector<int> a = {1,2,3,4,6,7,8,9,10,11,12,13,14,15};
    int N = 14;
    cout<<missingNumber(a,N);
    
    return 0;
}