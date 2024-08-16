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

Node* reverseLL(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void reverseRecursion(Node* &head,Node* curr,Node* prev){

    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverseRecursion(head,forward,curr);
    curr->next = prev;
}

void print(Node* head){
    if(head == NULL){
        cout<<"LIST IS EMPTY!"<<endl;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{   
    Node* head;
    Node* n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);
    Node *n6 = new Node(60);
    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head);
    head = reverseLL(head);
    print(head);

    return 0;
}