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

void rightView(Node* root,int level,vector<int> &res){
    if(root == NULL){
        return;
    }

    if(res.size() == level){
        res.push_back(root->data);
    }

    rightView(root->right,level+1,res);
    rightView(root->left,level+1,res);
}

void rightView(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }

    if (res.size() == level)
    {
        res.push_back(root->data);
    }

    rightView(root->left, level + 1, res);
    rightView(root->right, level + 1, res);
}

int main()
{
    return 0;
}