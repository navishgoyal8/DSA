#include <iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }

            isTerminal = false;     
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // T.C = O(L) where L is the length of the word
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumptions that words will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //RECURSION
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    // T.C = O(L) where L is the length of the word
    bool searchUtil(TrieNode* root,string word){

        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }

        //RECURSION
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main()
{   
    Trie t;
    
    t.insertWord("HELLO");
    t.insertWord("HELL");
    t.insertWord("HE");
    t.insertWord("WORLD");
    t.insertWord("WORLDWIDE");
    cout<<t.searchWord("HELO")<<endl;

    return 0;
}