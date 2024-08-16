#include <iostream>
using namespace std;

string replaceSpaces(string &str){
    string ans = "";

    for(int i=0;i<str.length();i++){
        if(str[i] == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else{
            ans.push_back(str[i]);
        }
    }

    return ans;
}

int main()
{   
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    cout<<"After replacing spaces: "<<replaceSpaces(str)<<endl;

    return 0;
}