#include <iostream>
#include <math.h>
using namespace std;

double morePrecision(int n,int precision,int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0;i<precision;i++){
        factor = factor/10;

        for(double j=ans;j*j<n;j=j+factor){
            ans = j;
        }
    }

    return ans;
}


int main()
{   
    int num;
    cout<<"Enter the number:";
    cin >> num;

    int start = 0;
    int end = num;
    int ans = 0;
    int mid = start + (end - start)/2;

    while(start <= end){

        int square = mid * mid;
        if(square == num){
            ans = mid;
            break;
        }

        if(square < num){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid-1;
        }

        mid = start + (end - start)/2; 

    }

    cout<<ans<<endl;

    double decimal = morePrecision(num,4,ans);

    cout<<decimal<<endl;

    return 0;
}