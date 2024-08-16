#include <iostream>
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

int widthOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id = q.front().second - min;
            Node* node = q.front().first;
            q.pop();
            if(i == 0){
                first = cur_id;
            }
            if(i == size-1){
                last = cur_id;
            }
            if(node->left != NULL){
                q.push({node->left,2*cur_id+1});
            }

            if(node->right != NULL){
                q.push({node->right,2*cur_id+2});
            }
        }

        ans = max(ans,last-first+1);
    }

    return ans;
}

int main()
{
    return 0;
}