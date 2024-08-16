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

void inorderTraversal(Node* root,vector<int> &inorder){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right,inorder);
}

void preorderTraversal(Node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void fillPreOrder(Node* root,vector<int> inorder,int *i){

    if(root == NULL){
        return;
    }

    root->data = inorder[++*i];
    fillPreOrder(root->left,inorder,i);
    fillPreOrder(root->right,inorder,i);
}

int main()
{   
    vector<int> inorder;
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // cout<<"Previous Tree was as follows:"<<endl;
    int i = -1;
    inorderTraversal(root,inorder);
    fillPreOrder(root,inorder,&i);

    preorderTraversal(root);

    

    return 0;
}