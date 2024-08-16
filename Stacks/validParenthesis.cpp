#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s){

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
}


bool validParenthesis(string str){
    
    stack<char> s;
    for(int i=0;i<str.length();i++){

        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if (str[i] == ')' && top == '(' || str[i] == '}' && top == '{' || str[i] == ']' && top == '['){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{    
    stack<int> s;
    string str;
    cout<<"Enter the string:";
    cin >> str;

    if(validParenthesis(str)){
        cout<<"Valid Parenthesis"<<endl;
    }
    else{
        cout<<"Invalid Parenthesis"<<endl;
    }



    return 0;
}