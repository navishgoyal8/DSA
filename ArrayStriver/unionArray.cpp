#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> sortedArray(vector<int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(a[i]);
    }

    for(int i=0;i<n2;i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it: st){
        temp.push_back(it);
    }

    return temp;
}

vector<int> sortedArrayOptimal(vector<int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> unionArray;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(unionArray.size() == 0 || unionArray.back() != a[i]){
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else{
            if (unionArray.size() == 0 || unionArray.back() != b[j])
            {
                unionArray.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if (unionArray.size() == 0 || unionArray.back() != a[i])
        {
            unionArray.push_back(a[i]);
        }
        i++;
    }

    while(j<n2){
        if (unionArray.size() == 0 || unionArray.back() != b[j])
        {
            unionArray.push_back(b[j]);
        }
        j++;
    }

    return unionArray;
}

int main()
{   
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {3,4,5,6,7};
    vector<int> res = sortedArray(a,b);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;
    vector<int> res1 = sortedArrayOptimal(a,b);
    for(int i=0;i<res1.size();i++){
        cout<<res1[i]<<" ";
    }
    

    return 0;
}