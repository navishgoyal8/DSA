#include <iostream>
#include <vector>
using namespace std;

void solve(string digits,int index,string output,vector<string> &ans,string mapping[]){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,index+1,output,ans,mapping);

        //backtrack
        output.pop_back();
    }
}


vector<string> phoneKeypad(string &digits){
    string output;
    vector<string> ans;
    if(digits.length() == 0){
        return ans;
    }
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,index,output,ans,mapping);

    return ans;
}

int main()
{   
    string digits = "54";
    vector<string> ans;

    ans = phoneKeypad(digits);

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}