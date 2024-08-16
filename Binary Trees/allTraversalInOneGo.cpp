#include <iostream>
#include <vector>
#include <stack>
#include <utility>
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

vector<int> prePostInTraversal(Node* root){
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> preorder,inorder,postorder;
    if(root == NULL){
        return;
    }

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            postorder.push_back(it.first->data);
        }
}
    
    
}

int main()
{   

    return 0;
}