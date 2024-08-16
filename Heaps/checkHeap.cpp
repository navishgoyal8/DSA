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

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root,int index,int totalCount){
    if(root == NULL){
        return true;
    }

    if(index >= totalCount){
        return false;
    }

    return isCBT(root->left,2*index+1,totalCount) && isCBT(root->right,2*index+2,totalCount);
}

bool isMaxOrder(Node* root){
    
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return root->data >= root->left->data;
    }

    else{
        return root->data >= root->left->data && root->data >= root->right->data && isMaxOrder(root->left) && isMaxOrder(root->right);
    }
}

// T.C = O(n) + O(n) + O(n) = O(n)
bool isHeap(Node* root){
    int index = 0;
    int totalCount = countNodes(root);

    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{   
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);

    if(isHeap(root)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    return 0;
}