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

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    
    return 1 + max(left,right);
}


int main()
{
    return 0;
}