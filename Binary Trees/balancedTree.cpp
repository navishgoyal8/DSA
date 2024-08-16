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


// if not balanced then return -1 unless it will return height of tree
int isBalancedOptimal(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = isBalancedOptimal(root->left);
    if(left == -1){
        return -1;
    }
    
    int right = isBalancedOptimal(root->right);
    if(right == -1){
        return -1;
    }

    if(abs(left-right) > 1){
        return -1;
    }

    return 1 + max(left, right);
}


int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return 1 + max(left, right);
}

bool isBalancedLessOptimal(Node* root){
    if(root == NULL){
        return true;
    }

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    if(abs(lh-rh) > 1){
        return false;
    }

    bool isLeftBalanced = isBalancedLessOptimal(root->left);
    bool isRightBalanced = isBalancedLessOptimal(root->right);

    if(!left || !right){
        return false;
    }

    return true;
}

int main()
{
    return 0;
}