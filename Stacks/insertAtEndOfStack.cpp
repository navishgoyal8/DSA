#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    int n = myStack.size();

    solve(myStack, x);

    return myStack;
}

void print(stack<int> myStack)
{
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;
}

int main()
{   
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    int x = 100;
    print(myStack);
    myStack = pushAtBottom(myStack, x);
    print(myStack);


    return 0;
}