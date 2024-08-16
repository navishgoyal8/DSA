#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr,int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n ; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestHistogram(vector<int> &heights){

        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights,n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);

        int area = INT_MIN;;
        for(int i=0;i<n;i++){
            int length = heights[i];
            if(next[i] == -1)
            {
                next[i] = n;
            }

            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;

            area = max(area,newArea);
        }

        return area;
}

int main()
{   
    vector<int> heights = {2,1,5,6,2,3};
    cout<<largestHistogram(heights)<<endl;

    return 0;
}