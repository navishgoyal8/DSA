#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *removeDuplicateSort(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            Node *node1 = temp->next->next;
            Node *node2 = temp->next;
            delete(node2);
            temp->next = node1;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

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

void print(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = input_data();

    head = removeDuplicateSort(head);

    print(head);

    return 0;
}