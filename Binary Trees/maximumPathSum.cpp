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

int maxPathDown(Node* node,int &maxi){
    if(node == NULL){
        return 0;
    }

    int left = max(0,maxPathDown(node->left,maxi));
    int right = max(0,maxPathDown(node->right,maxi));
    maxi = max(maxi,left+right+node->data);

    return max(left,right)+node->data;  
}

int maxPathSum(Node* root){
    int maxi = INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int main()
{
    return 0;
}