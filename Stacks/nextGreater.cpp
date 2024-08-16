#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C => O(2*N)
// S.C => O(N) + O(N)
vector<int> nextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

vector<int> nextGreaterElement2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 2*n-1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i%n])
        {
            st.pop();
        }
        if(i < n){
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
        }
        st.push(arr[i%n]);
    }
   
    return ans;
}

int main()
{   
    vector<int> arr = {1,3,2,4};
    vector<int> ans = nextGreaterElement(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;
    vector<int> arr1 = {1, 3,6, 2, 5,4};
    vector<int> ans1 = nextGreaterElement2(arr1);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }

    return 0;
}