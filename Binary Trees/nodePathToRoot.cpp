#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node* root,vector<int>& arr,int x){
    if(!root){
        return false;
    }

    arr.push_back(root->data);
    if(root->data == x){
        return true;
    }

    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)){
        return true;
    }

    arr.pop_back();
    return false;
}

int main()
{
    return 0;
}