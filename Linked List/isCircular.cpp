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

bool isCircular(Node *head)
{
    Node *temp = head;

    if (head == NULL)
    {
        return true;
    }

    if (head->next == NULL)
    {
        return false;
    }

    while (temp->next != NULL)
    {

        if (temp->next == head)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

// APPROACH2 -----> USING MAP FUNCTION BY DOING WHETHER THE NODE IS VISITED OR NOT IN THE MAP FUNCTION

int main()
{   
    
    return 0;
}