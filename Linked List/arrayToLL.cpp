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

Node* arrayToLinkedList(int* arr,int n){

    Node* head;
    cout<<head->data;
    if (n == 0)
    {
        return head;
    }
    head = new Node(arr[0]);
    Node* first = head;
    Node* second;
    int i = 1;
    while(i<n){
        
        second = new Node(arr[i]);
        first->next = second;
        first = second;
        i++;
    }

    return head;
}

void print(Node* head){
    Node* temp = head;
    if(head == NULL){
        cout<<"LIST IS EMPTY!";
    }
    else{
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main()
{   
    int arr[10];
    int n = 0;

    Node* head = arrayToLinkedList(arr,n);
    print(head);

    return 0;
}