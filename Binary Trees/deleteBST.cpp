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

Node* deleteNode(Node* root,int key){
    if(root == NULL){
        return root;
    }
    if(root->data == key){
        return helper(root);
    }
    Node* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else{
            root = root->left;
            }
        }
        else{
            if(root->right && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else{
            root = root->right;
            }
        }
    }

    return dummy;
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }

    if(root->right == NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastChild = findLastRight(root->left);
    lastChild->right = rightChild;
    return root->left;
}

Node* findLastRight(Node* root){
    if(root->right == NULL){
        return root;
    }

    return findLastRight(root->right);
}

int main()
{
    return 0;
}