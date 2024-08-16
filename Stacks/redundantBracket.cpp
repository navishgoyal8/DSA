#include <iostream>
#include <stack>
using namespace std;

bool redundantBracket(string& str){
    stack<char> st;

    for(int i=0;i<str.length();i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){

                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true){
                    return true;
                }

                st.pop();
            }
        }
    }

    return false;
}

int main()
{   
    string str;
    cout<<"Enter the expression: ";
    cin >> str;
    if(redundantBracket(str)){
        cout<<"Redundant Bracket"<<endl;
    }
    else{
        cout<<"Not a Redundant Bracket"<<endl;
    }

    return 0;
}