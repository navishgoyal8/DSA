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

int findLength(Node* slow,Node* fast){
    int count = 1;
    fast = fast->next;
    while(fast != slow){
        fast = fast->next;
        count++;
    }

    return count;
}

int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        if(slow == fast){
            return findLength(slow,fast);
        }
    }

    return 0;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    return 0;
}