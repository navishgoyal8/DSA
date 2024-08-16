#include <iostream>
#include <vector>
using namespace std;

void solve(string output, int index, string str, vector<string> &ans){

    if (index >= str.length())
    {
        if (output.length() > 0)  // TO REMOVE THE EMPTY STRING SUBSEQUENCE
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(output, index + 1, str, ans);

    // include
    int element = str[index];
    output.push_back(element);
    solve(output, index + 1, str, ans);

}

vector<string> subsequence(string str)
{
    string output = "";
    int index = 0;
    vector<string> ans;
    solve(output,index,str,ans);

    return ans;
}

int main()
{   
    string str = "abc";
    string output = "";
    int index = 0;
    vector<string> ans;

    ans = subsequence(str);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}