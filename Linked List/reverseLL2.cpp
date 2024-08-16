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

Node* reverseLL2(Node* head,int left,int right){
    if (left == right)
    {
        return head;
    }

    Node *leftNode = head;
    Node *rightNode = head;

    int index = 2;
    
    while (index < left)
    {
        leftNode = leftNode->next;
        index++;
    }
    
    index = 1;
    while (index < right)
    {
        rightNode = rightNode->next;
        index++;
    }
    
    Node* second;
    Node *temp = NULL;
    Node *first = NULL;
    if(left != 1){
        second = leftNode->next;
    }
    else{
        second = head;
    }
   
    Node* extreme = rightNode->next;
    while (second != extreme)
    {
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }

   if(left != 1){
        leftNode->next = first;
   }

   Node* tail = first;

   while(tail->next != NULL){
        tail = tail->next;
   }

   tail->next = extreme;

   if(left == 1){
       return first;
   }
   else{
         return head;
   }
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
    int left = 1;
    int right = 2;

    head = reverseLL2(head,left,right);
    print(head);

    return 0;
}