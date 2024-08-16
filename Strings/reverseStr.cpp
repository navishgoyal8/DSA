#include <iostream>
using namespace std;
int main()
{   
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    int n = str.length();
    cout<<"Before reversing: "<<str<<endl;
    char left = 0;
    char right = n-1;
    while(left<=right){
        swap(str[left],str[right]);
        left++;
        right--;
    }

    cout<<"After reversing: "<<str<<endl;

    return 0;
}