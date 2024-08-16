// reverse the string using recursion

#include <iostream>
using namespace std;

void reverseStr(string &str,int i,int j){
    
    if(i>j){
        return;
    }

    swap(str[i],str[j]);
    i++;
    j--;
    reverseStr(str,i,j);
}

int main()
{   
    string str;
    cout<<"Enter the string:";
    cin >> str;
    int start = 0;
    int end = str.length()-1;

    reverseStr(str,start,end);
    cout<<str;
    return 0;
}