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

Node* searchBST(Node* root,int val){

    while(root != NULL && root->data != val){
        root = val < root->data ? root->left : root->right;
    }

    return root;
}

int main()
{
    return 0;
}