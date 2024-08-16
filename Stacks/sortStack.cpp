#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int x)
{
    if (st.empty() || st.top() > x)
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(num);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack, num);
}

void print(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << endl;
}

int main()
{   
    stack<int> stack;
    stack.push(10);
    stack.push(0);
    stack.push(300);
    stack.push(40);
    stack.push(20);
    stack.push(60);
    print(stack);
    sortStack(stack);
    print(stack);

    return 0;
}