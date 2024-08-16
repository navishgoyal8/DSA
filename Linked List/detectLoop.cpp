#include <iostream>
#include <map>
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

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head;
    map<Node *, bool> visited;

    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *floydDetection(Node *head)
{

    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {
            return slow;
        }
    }

    return NULL;
}

Node *beginingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *intersection = floydDetection(head);
    if(intersection == NULL){
        return NULL;
    }

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startLoop = beginingNode(head);

    if(startLoop == NULL)
    {
        return head;
    }

    Node *temp = startLoop;
    while (temp->next != startLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

int main()
{
    return 0;
}