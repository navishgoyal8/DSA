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

// val <= key
int findFloor(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }

        if(key > root->data){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }

    return floor;
}

int main()
{
    return 0;
}