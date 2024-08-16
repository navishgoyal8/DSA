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

int findDiameter(Node* root,int diameter){
    if(root == NULL){
        return 0;
    }

    int left = findDiameter(root->left,diameter);
    int right = findDiameter(root->right,diameter);
    diameter = max(diameter,left+right);

    return 1 + max(left,right);

}

int main()
{
    return 0;
}