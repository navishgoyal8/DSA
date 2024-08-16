#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &tail,int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node* &head,int data,int position){
    Node* temp = head;
    Node* newNode = new Node(data);
    int count = 1;
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(head,data);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

}


void deleteNode(Node* head,int position){

    Node* temp = head;
    if(position == 1){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{   
    Node* head;
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    head = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    print(head);

    insertAtHead(head,896);
    print(head);

    insertAtPos(head,56,3);
    print(head);

    return 0;
}