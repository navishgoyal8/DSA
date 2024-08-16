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

Node *input_data()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node* reverseLL(Node* head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* first = NULL;
    Node* temp = NULL;
    Node* second = head;

    while(second != NULL){
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }

    return first;
}

Node* addTwoNumbers1(Node* head1,Node* head2){
    Node* first = reverseLL(head1);
    Node* second = reverseLL(head2);
    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    while(first != NULL || second != NULL){
        int sum = carry;
        if(first != NULL){
            sum += first->data;
            first = first->next;
        }
        if(second != NULL){
            sum += second->data;
            second = second->next;
        }

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    Node* head = reverseLL(dummyNode->next);
    return head;
}


Node* addTwoNumbers2(Node* head1,Node* head2){

    long long num1 = 0;
    long long num2 = 0;
    while(head1 != NULL || head2 != NULL){
        if(head1 != NULL){
            num1 = num1*10 + head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            num2 = num2*10 + head2->data;
            head2 = head2->next;
        }
    }
    
    long long sum = num1 + num2;
    
    int first = sum%10;
    Node* head = new Node(first);
    sum = sum/10;
    Node* temp = head;
    while(sum != 0){
        int digit = sum%10;
        Node* newNode = new Node(digit);
        temp->next = newNode;
        temp = temp->next;
        sum = sum/10;
    }

    return head;
    }


void print(Node* head){

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{   
    Node* head1 = input_data();
    Node* head2 = input_data();
    print(head1);
    print(head2);
    Node* head = addTwoNumbers1(head1,head2);
    print(head);
    

    return 0;
}