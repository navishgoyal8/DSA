#include <iostream>
#include <vector>
#include <stack>
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

vector<int> iterativeInorder(Node* root){
    vector<int> inorder;
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node = st.top();
            inorder.push_back(node->data);
            node = node->right;
        }
    }

    return inorder;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    return 0;
}