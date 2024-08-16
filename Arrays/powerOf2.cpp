#include <iostream>
#include <math.h>
using namespace std;

bool isPowerOfTwo(int n){
    if(n == 0){
        return false;
    }
    if(n == 1){
        return true;
    }

    if(n % 2 == 0){
        return isPowerOfTwo(n/2);
    }
    else{
        return false;
    }
}

int main()
{   
    int n;
    cout<<"Enter the number:";
    cin >> n;

    //ITERATIVE SOLUTION
    for(int i=0;i<=n;i++){
        if(pow(2,i) == n){
            cout<<"YES!"<<endl;
            break;
        }
    }

    //RECURSIVE SOLUTION

    if(isPowerOfTwo(n)){
        cout<<"YES!"<<endl;
    }
    else{
        cout<<"NO!"<<endl;
    }

    return 0;
}