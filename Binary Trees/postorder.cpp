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

vector<int> postOrderUsingTwoStacks(Node* root){
    vector<int> postorder;
    if(root == NULL){
        return postorder;
    }
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* top = st1.top();
        st1.pop();
        st2.push(top);
        if(top->left != NULL){
            st1.push(top->left);
        }
        if(top->right != NULL){
            st1.push(top->right);
        }
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

// T.C => O(2*N)
// S.C => O(N)
vector<int> postorderUsingOneStack(Node* root){
    vector<int> postorder;
    stack<Node*> st; 
    Node* curr = root;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }

    return postorder;
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    return 0;
}