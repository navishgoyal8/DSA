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
            head = newNode;
            tail = newNode;
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

int getLength(Node* head){

    if(head == NULL)
    {
        return 0;
    }
    int len = 0;

    while(head != NULL)
    {
        len++;
        head = head->next;
    }

    return len;
}

Node* middleElement1(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

Node* middleElement2(Node* head){
    int len = getLength(head);
    len = (len/2);

    Node* temp = head;
    int count = 0;
    while(count < len){
        count++;
        temp = temp->next;
    }
    
    return temp;
}

int main()
{   
    Node* head = input_data();
    print(head);

    cout<<middleElement1(head)->data<<"  "<<middleElement2(head)->data;

    return 0;
}