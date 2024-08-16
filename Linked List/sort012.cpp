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

Node* sort012better(Node* head){
    
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    return zeroHead->next;

}


Node* sort012(Node *head)
{

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    Node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }

        temp = temp->next;
    }

    temp = head;
    

    while (zeroCount--)
    {
        Node *newNode = new Node(0);
        curr->next = newNode;
        curr = curr->next;
    }

    while (oneCount--)
    {
        Node *newNode = new Node(1);
        curr->next = newNode;
        curr = curr->next;
    }

    while (twoCount--)
    {
        Node *newNode = new Node(2);
        curr->next = newNode;
        curr = curr->next;
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
    Node* head = input_data();
    print(head);
    Node* better = sort012better(head);
    print(better);
    Node* newHead = sort012(head);
    print(newHead);

    return 0;
}