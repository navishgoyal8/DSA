#include <iostream>
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

Node* input_data(){
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            tail = newNode;
            head = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }

    return head;
}

void print(Node* head){
    if(head == NULL){
        cout<<"LIST IS EMPTY!"<<endl;
    }
    else{
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

Node* kreverse(Node* head,int k){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = kreverse(next,k);
    }

    return prev;
}

int main()
{   
    Node* head = input_data();
    print(head);
    int k;
    cout<<"Enter the value of k:";
    cin >> k;
    head = kreverse(head,k);
    print(head);
    return 0;
}