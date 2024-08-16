#include <iostream>
using namespace std;
int main()
{   
    int arr[7]={1,2,3,3,2,1,10};
    
    int ans = 0;

    for(int i=0;i<7;i++){
        ans = ans^arr[i];
    }

    cout<<ans<<endl;

    return 0;
}