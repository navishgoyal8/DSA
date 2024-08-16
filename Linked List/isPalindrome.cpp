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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *first = NULL;
    Node *second = head;
    Node *temp = NULL;

    while (second != NULL)
    {
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }

    return first;
}

bool isPalindrome(Node *head)
{   
   if(head == NULL || head->next == NULL){
        return true;
   }

   Node* slow = head;
   Node* fast = head;
   while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
   }

   Node* newHead = reverseLL(slow->next);
   Node* first = head;
   Node* second = newHead;
   while(second != NULL){
    if(first->data != second->data){
        return false;
    }
    first = first->next;
    second = second->next;
   }

   reverseLL(newHead);

   return true; 

}

int main()
{   
    Node* head = input_data();
    print(head);
    if(isPalindrome(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}