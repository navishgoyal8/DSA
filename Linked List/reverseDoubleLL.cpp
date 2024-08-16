#include <iostream>
#include <stack>
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

void insertData(Node* &head,Node* &tail,int data){

    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

}

void print(Node* head){
    if(head == NULL){
        cout<<"List is empty!"<<endl;
    }
    else{
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

Node* reverseLL1(Node* head){

    //Replacing the data elements
    if(head == NULL || head->next == NULL){
        return head;
    }

    stack <int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}


Node* reverseLL2(Node* head){

    //Replacing the connections between the nodes
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* second = head;
    Node* first = NULL;
    Node* temp = NULL;

    while(second != NULL){
        temp = second->next;
        second->next = first;
        second->prev = temp;
        first = second;
        second = temp;
    }

    return first;
}


int main()
{   
    Node* head = NULL;
    Node* tail = NULL;
    insertData(head,tail,20);
    insertData(head, tail,10);
    insertData(head,tail, 30);
    insertData(head,tail, 40);
    insertData(head, tail,50);
    insertData(head, tail,60);
    insertData(head,tail, 70);
    print(head);

    Node* head1 = reverseLL1(head);
    print(head1);

    Node* head2 = reverseLL2(head);
    print(head2);

    return 0;
}