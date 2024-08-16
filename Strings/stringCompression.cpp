#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &chars){
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while(i<n){
        int j = i+1;
        while(j<n && chars[j]==chars[i]){
            j++;
        }

        chars[ansIndex++] = chars[i];
        int count = j-i;
        if(count>1){
            string temp = to_string(count);
            for(char ch: temp){
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    return ansIndex;
}

int main()
{   
    vector<char> chars = {'a','b','b','c','c','c'};
    int n = compress(chars);
    for(int i=0;i<n;i++){
        cout<<chars[i]<<" ";
    }
    cout<<endl;

    return 0;
}