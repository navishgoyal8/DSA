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

Node* oddEvenListIndex(Node* head){
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}


Node* oddEvenListNodes(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    
}

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
    Node* head = input_data();
    print(head);
    head = oddEvenListIndex(head);
    print(head);

    return 0;
}