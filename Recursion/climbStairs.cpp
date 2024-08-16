#include <iostream>
using namespace std;

int stairs(int n){
    if(n<0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    return stairs(n-1) + stairs(n-2);
}

int main()
{   
    int n;
    cout<<"Enter the stair number:";
    cin>>n;

    int ans = stairs(n);
    cout<<ans<<endl;

    return 0;
}