#include <iostream>
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

// val >= key 
int findCeil(Node* root,int key){
    int ceil = -1;
    while(root){

        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int main()
{
    return 0;
}