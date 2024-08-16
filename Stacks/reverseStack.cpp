#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(num);
}

void reverseStackRecursion(stack<int>& s){
    if(s.empty()){
        return;
    }
    
    int num = s.top();
    s.pop();
    reverseStackRecursion(s);
    insertAtBottom(s,num);
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{   
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    print(s);
    reverseStackRecursion(s);
    print(s);
    
    return 0;
}