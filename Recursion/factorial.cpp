#include <iostream>
using namespace std;

int factorial(int num){
    if(num == 0){
        return 1;
    }

    return num * factorial(num - 1);
}

int main()
{   
    int n;
    cout<<"Enter the number:";
    cin >> n;

    int ans = factorial(n);

    cout<<ans<<endl;

    return 0;
}