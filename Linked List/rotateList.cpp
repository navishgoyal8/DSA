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

Node* findNthNode(Node* temp,int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k){
            return temp;
        }

        cnt++;
        temp = temp->next;
    }

    return temp;
}

Node* rotateRight(Node *head, int k)
{   
    if(head == NULL || k == 0){
        return head;
    }
    Node* tail = head;
    int len = 1;

    while(tail->next != NULL){
        tail = tail->next;
        len++;
    }

    k = k % len;

    if(k == 0){
        return head;
    }
    else{
        tail->next = head;
        Node* newLastNode = findNthNode(head,len-k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
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
    int k = 2;
    head = rotateRight(head, k);
    print(head);

    return 0;
}