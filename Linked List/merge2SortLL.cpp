#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
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
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node* mergeTwoLL(Node* head1,Node* head2){
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }

    if(head1 == NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;

    while(temp1 != NULL && temp2 != NULL){

        if(temp1->data <= temp2->data){
            Node* newNode = new Node(temp1->data);
            curr->next = newNode;
            curr = curr->next;
            temp1 = temp1->next;
        }
        else{
            Node* newNode = new Node(temp2->data);
            curr->next = newNode;
            curr = curr->next;
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL){
        Node* newNode = new Node(temp1->data);
        curr->next = newNode;
        curr = curr->next;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        Node *newNode = new Node(temp2->data);
        curr->next = newNode;
        curr = curr->next;
        temp2 = temp2->next;
    }


    return dummyNode->next;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{   
    Node* head1 = input_data();
    print(head1);
    Node* head2 = input_data();
    print(head2);
    Node* newHead = mergeTwoLL(head1,head2);
    print(newHead);

    return 0;
}