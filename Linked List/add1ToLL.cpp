#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* input_data()
{
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)
    {
        Node* newNode = new Node(data);
        if(head == NULL)
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

int helper(Node* temp){

    if(temp == NULL){
        return 1;
    }

    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }

    temp->data = 0;
    return 1;
}

Node* addOneToLLRecursion(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

Node* reverseLL(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = NULL;
    Node* first = NULL;
    Node* second = head;

    while(second != NULL){
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }

    return first;
    
}

Node* addOneToLL(Node* head){
    
    if(head == NULL){
        return head;
    }

    Node* temp = head;
    int num  = 0;
    while(temp != NULL){
        num = 10*num + temp->data;
        temp = temp->next;
    }

    num += 1;

    Node* initial = new Node(num%10);
    num = num / 10;
    Node* curr = initial;

    while(num != 0){
        
        Node* newNode = new Node(num%10);
        curr->next = newNode;
        curr = curr->next;
        num = num / 10;
    }

    return initial;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{   
    Node* head = input_data();
    print(head);
    head = addOneToLLRecursion(head);
    print(head);

    return 0;
}