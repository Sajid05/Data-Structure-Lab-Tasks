#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


Node* insertFirst(Node *head, int value);
Node* insertEnd(Node *head, int value);
Node* insertAnywhere(Node *head, int value, int key);
void display(Node* head);

int main ()
{
    int num_of_operations;
    cout << "Enter number of operations : ";
    cin >> num_of_operations;
    Node *head = NULL;
    while(num_of_operations--)
    {
        int options, value;
        cin >> options;
        switch(options)
        {
        case 1:
            cin >> value;
            head = insertFirst(head, value);
            display(head);
            break;
        case 2:
            cin >> value;
            head = insertEnd(head, value);
            display(head);
            break;
        case 3:
            int key;
            cin >> key >> value;
            head = insertAnywhere(head, value, key);
            display(head);
            break;
        default:
            break;
        }
    }
}


Node* insertFirst(Node *head, int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    temp->next = head;
    head = temp;
    return head;

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
    while(temp1->next != NULL) //when the condition is true temp1 points to last node
    {
        temp1 = temp1->next;
    }

    temp1->next = temp2;
    return head;
}

Node* insertAnywhere(Node *head, int value, int key)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    temp2->data = value;
    temp2->next = NULL;
    if(head == NULL)
    {
        cout << "Invalid Input " << endl;
        return head;
    }
    while(temp1->data != key)
    {
        temp1 = temp1->next;
        if(temp1 == NULL) //  if whole link list is traversed but value not found
        {
            cout << "Invalid Input" << endl;
            return head;
        }
    }

    temp2->next = temp1->next;
    temp1->next = temp2;

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
