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

bool checkSymmetric(Node* left,Node* right){
    if(left == NULL || right == NULL){
        return (left == right);
    }
    if(left->data != right->data){
        return false;
    }
    return checkSymmetric(left->left,right->right) && 
           checkSymmetric(left->right,right->left);
}

bool isSymmetric(Node* root){
    return root == NULL || checkSymmetric(root->left,root->right);
}
int main()
{
    return 0;
}