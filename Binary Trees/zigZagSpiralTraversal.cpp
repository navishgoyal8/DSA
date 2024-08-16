#include <iostream>
#include <vector>
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

// T.C = O(N)
// S.C = O(N)
vector<vector<int>> zigzagLevelOrder(Node* root){
    vector<vector<int>> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();

            //find position to fill the nodes values
            int index = (leftToRight) ? i : (size-1-i);
            row[index] = node->data;
            if(node->left != NULL){
                q.push(node->left);
            }

            if(node->right != NULL){
                q.push(node->right);
            }
        }

        //after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }

    return result;
}

int main()
{
    return 0;
}