#include <iostream>
#include <stack>
using namespace std;
int main()
{   
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<< s.size() << endl;
    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
    
cout<< endl;

    if(s.empty()){
        cout<<"Stack is empty!";
    }
    else{
        cout<<"Stack is not empty!";
    }


    return 0;
}