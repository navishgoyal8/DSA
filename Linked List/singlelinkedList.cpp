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


Node* insertHead(Node* head,int data){

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    return head;
}

Node* insertTail(Node* head,int data){
    Node* tail = head;
    Node* newNode = new Node(data);
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = newNode;

    return head;
}

Node* insertPos(Node* head,int data,int position){
    Node* temp = head;

    if(position == 1){
        head = insertHead(head,data);
        return head;
    }

    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        head = insertTail(head,data);
        return head;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* deleteNode(Node* head,int position){

    Node* temp = head;
    if(position == 1){
        Node* n = head->next;
        head = n;
        return head;
    }

    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    Node* n1 = temp->next;
    temp->next = n1->next;

    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{   
    Node *head;
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    head = n1;
    n1->next = n2;
    n2->next = n3;

    print(head);
    
    head = insertHead(head,56);
    print(head);

    head = insertTail(head,89);
    print(head);
    
    head = insertPos(head,563,3);
    print(head);

    head = deleteNode(head,1);
    print(head);

    head = deleteNode(head, 5);
    print(head);

    return 0;
}