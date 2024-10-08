#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    int i;
    int j;

    Node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
     bool operator()(Node* a,Node* b){
        return a->data > b->data;
     }
};

// T.C = O(n*K*logk)
// S.C = O(n*k)
vector<int> mergeKsortedArrays(vector<vector<int>> &kArrays,int k){
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    //step1: saare arrys ke k first elements insert h
    for(int i=0;i<k;i++){
        Node* temp = new Node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;
    //step2: 
    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArrays[i].size()){
            Node* next = new Node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main()
{   
    vector<vector<int>> kArrays = {{2,6,12,15},
                                   {1,3,14,20},
                                   {3,5,8,10}};
    int k = kArrays.size();
    vector<int> ans = mergeKsortedArrays(kArrays,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}