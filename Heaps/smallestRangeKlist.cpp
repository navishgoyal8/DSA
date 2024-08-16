#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int r,int c){
        this->data = data;
        row = r;
        col = c;
    }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a,int k,int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    for(int i=0;i<k;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new Node(element,i,0));
    }

    int start = mini;
    int end = maxi;

    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col+1 < n){
            maxi = max(maxi,a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }

    return end - start + 1;
}

int main()
{   
    vector<vector<int>> a = {{4,7,9,12,15},
                              {0,8,10,14,20},
                              {6,12,16,30,50}};
    int k = a.size();
    int n = a[0].size();
    cout<<kSorted(a,k,n);
    
    return 0;
}