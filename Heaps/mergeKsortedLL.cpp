#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

// T.C = O(n*k*logk) where n*k is the total number of nodes in all the linked lists
// S.C = O(k)
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    int k = listArray.size();
    if(k == 0){
        return NULL;
    }
    //step1:
    for(int i=0;i<k;i++){
        if(listArray[i] != NULL){
        minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        minHeap.pop();

        if(temp->next != NULL){
            minHeap.push(temp->next);
        }

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }

    }
    
    return head;
}

int main()
{   
    Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);
    
    return 0;
}