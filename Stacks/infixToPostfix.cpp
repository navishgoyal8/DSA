#include <iostream>
#include <stack>
using namespace std;

string infixToPostfix(string s){
    int i = 0;
    stack<char> st;
    string ans = "";
    while(i < s.length()){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <= '9') ){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && st.top() != '(' && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        } 
    }
}

int main()
{
    return 0;
}