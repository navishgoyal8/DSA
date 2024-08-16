#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> iterativePreorder(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* top = st.top();
        st.pop();
        if(top->right != NULL){
            st.push(top->right);
        }
        if(top->left != NULL){
            st.push(top->left);
        }

        ans.push_back(top->data);
    }

    return ans;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    return 0;
}