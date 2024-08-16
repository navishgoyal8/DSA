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

// T.C = O(logN * logN)
// S.C = O(logN)
int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh){
        return (1<<lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findHeightLeft(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }

    return height;
}

int findHeightRight(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }

    return height;
}

int main()
{
    return 0;
}