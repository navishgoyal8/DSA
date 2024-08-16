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

Node* lowestCommonAncestor(Node* root,Node* p,Node* q){

    //base case
    if(root == NULL || root == p || root == q){
        return root;
    }

    Node* left = lowestCommonAncestor(root->left,p,q);
    Node* right = lowestCommonAncestor(root->right,p,q);

    //result
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        //both left and right are not null, we found our result
        return root;
    }
}

int main()
{
    return 0;
}