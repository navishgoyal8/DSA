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

Node* deleteMiddle(Node* head){

    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while(fast != NULL  && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
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
    head = deleteMiddle(head);
    print(head);

    return 0;
}