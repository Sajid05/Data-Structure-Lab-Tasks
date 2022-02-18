#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


Node* insertEnd(Node *head, int value);
void display(Node* head);

Node* deleteFirst(Node* head);
Node* deleteEnd(Node* head);
Node* deleteAnywhere(Node* head, int key);

int main ()
{
    int num_of_operations;

    Node *head = NULL;
    for(int i = 0, j = 10; i < 7; i++, j += 10)
    {
        head = insertEnd(head, j);
    }

    display(head);
    cout << "Enter number of operations : ";
    cin >> num_of_operations;
    while(num_of_operations--)
    {
        int options;
        cin >> options;
        switch(options)
        {
        case 1:
            head = deleteFirst(head);
            display(head);
            break;
        case 2:
            head = deleteEnd(head);
            display(head);
            break;
        case 3:
            int key;
            cin >> key;
            head = deleteAnywhere(head, key);
            display(head);
            break;
        default:
            break;
        }
    }
}



Node* insertEnd(Node *head, int value)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    temp2->data = value;
    temp2->next = NULL;

    if(head == NULL) // if linked list in empty
    {
        head = temp2;
        return head;
    }
    while(temp1->next != NULL) //when the condition is false temp1 points to last node
    {
        temp1 = temp1->next;
    }

    temp1->next = temp2;
    return head;
}

Node* deleteFirst(Node* head)
{
    Node *temp = new Node;
    temp = head;
    if(head == NULL)
    {
        cout << "No items to be deleted" << endl; // if list is empty
        return head;
    }
    head = temp->next;
    delete temp; //delete the node from heap explicitly
    return head;
}

Node* deleteEnd(Node* head)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    if(head == NULL)
    {
        cout << "No items to be deleted" << endl; // if list is empty
        return head;
    }
    if(temp1->next == NULL) // if there is only one node
    {
        head = NULL;
        delete temp1;
        return head;
    }
    while(temp1->next->next != NULL) // if condition is false temp1 points to the node before last node
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next; //temp2 points to last node
    delete temp2; //last node is deleted
    temp1->next = NULL;
    return head;
}

Node* deleteAnywhere(Node* head, int key)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    if(head == NULL)
    {
        cout << "No items to be deleted" << endl; // if list is empty
        return head;
    }
    if(temp1->data == key) // if there is only one node and that has the key
    {
        head = temp1->next;
        delete temp1;
        return head;   // in 132 and 138 lines we check this cases individually as 143 does not cover this cases
    }
    if(temp1->next == NULL) // if there is only one node but without key
    {
        cout << "Value not present" << endl;
        return head;
    }
    while(temp1->next->data != key) //if condition is false then temp1 points to the node that is before the node containing key
    {
        temp1 = temp1->next;
        if(temp1->next == NULL) // When value is not found(this is the last node)
        {
            cout << "Value not present" << endl;
            return head;
        }
    }
    temp2 = temp1->next; //temp2 points to the node to be deleted
    temp1->next = temp1->next->next;
    delete temp2;
    return head;
}


void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
