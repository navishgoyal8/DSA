#include <iostream>
#include <stack>
using namespace std;
int main()
{   
    string str;
    cout<<"Enter the string: ";
    cin >> str;
    int n = str.length();
    stack<int> st;
    int i = 0;
    while(str[i] != '\0'){
        st.push(str[i]);
        i++;
    }

    i = 0;
    while(!st.empty()){
        
        str[i] = st.top();
        st.pop();
        i++;
    }

    cout<<str<<endl;

    return 0;
}