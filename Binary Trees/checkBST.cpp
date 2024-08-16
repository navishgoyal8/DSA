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

bool isBST(Node* root,long minVal,long maxVal){
    if(root == NULL){
        return true;
    }
    if(root->data >= maxVal || root->data <= minVal){
        return false;
    }

    return isBST(root->left,minVal,root->data) && isBST(root->right,root->data,maxVal);
}

int main()
{
    return 0;
}