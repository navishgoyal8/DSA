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

// T.C = O(h) where h is the height of the tree which is log(n)
Node* insertIntoBST(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    Node* curr = root;
    while(true){
        if(curr->data <= val){
            if(curr->right != NULL){
                curr = curr->right;
            }
            else{
                curr->right = new Node(val);
                break;
            }
        }
        else{
            if(curr->left != NULL){
                curr = curr->left;
            }
            else{
                curr->left = new Node(val);
                break;
            }
        }
    }

    return root;
}

int main()
{
    return 0;
}