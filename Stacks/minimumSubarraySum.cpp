#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(int arr[],int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

vector<int> prevSmallerElement(int arr[],int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}


int sum(int arr[],int n){
    vector<int> nse = nextSmallerElement(arr,n);
    vector<int> pse = prevSmallerElement(arr,n);

    int total = 0;
    for(int i=0;i<n;i++){
        int left = i - pse[i] ;
        int right = nse[i] - i;
        total += arr[i] * left * right;
    }

    return total;
}   

int main()
{   
    int arr[] = {2,1,3,4,1,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sum(arr,n);

    return 0;
}