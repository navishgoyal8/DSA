#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word); 
    }

    void lcp(string str,string &ans){

        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefixTries(vector<string> &arr,int n){
    Trie t;

    for(int i=0;i<n;i++){
        t.insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t.lcp(first,ans);
    return ans;
}

// WITHOUT TRIES
string longestCommonPrefix(vector<string> &arr,int n){

    string ans = "";

    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];

        bool match = true;

        for(int j=1;j<n;j++){
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }

        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }

    return ans;
}

int main()
{   
    vector<string> arr = {"flower","flow","floght"};
    int n = arr.size();
    cout<<longestCommonPrefix(arr,n);

    cout<<endl;
    cout<<longestCommonPrefixTries(arr,n);

    return 0;
}