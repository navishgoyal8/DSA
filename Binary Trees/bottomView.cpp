#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    queue<pair<Node*,int>> q;
    map<int,int> mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left != NULL){
            q.push({node->left,line-1});
        }
        if(node->right != NULL){
            q.push({node->right,line+1});
        }

    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}


int main()
{
    return 0;
}