#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};


Node* insertFirst(Node *head, int value);
Node* insertEnd(Node *head, int value);
Node* insertAnywhere(Node *head, int value, int key);
void display(Node* head);

Node* deleteFirst(Node* head);
Node* deleteEnd(Node* head);
Node* deleteAnywhere(Node* head, int key);

void Reverse(Node *head) // for checking if doubly linked list works
{
    Node *temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main ()
{
    int num_of_operations;
    cout << "Enter number of operations : ";
    cin >> num_of_operations;
    Node *head = NULL;
    cout << "1. Insert At First\n2. Insert At End\n3. Insert with Key\n4. Delete from First\n5. Delete from End\n6. Delete with Key" << endl;
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
        case 4:
            head = deleteFirst(head);
            display(head);
            break;
        case 5:
            head = deleteEnd(head);
            display(head);
            break;
        case 6:
            cin >> key;
            head = deleteAnywhere(head, key);
            display(head);
            break;
        default:
            break;
        }
    }
    Reverse(head);
}


Node* insertFirst(Node *head, int value)
{
    Node *temp = new Node;
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    head->prev = temp; //the prev pointer of node pointed by head will be pointing to temp
    temp->next = head;
    head = temp;
    return head;

}

Node* insertEnd(Node *head, int value)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    temp2->prev = NULL;
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

    temp2->prev = temp1;
    temp1->next = temp2;

    return head;
}

Node* insertAnywhere(Node *head, int value, int key)
{
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    temp1 = head;
    temp2->prev = NULL;
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

    temp2->prev = temp1; //prev pointer of new node points to temp1
    temp2->next = temp1->next; //next pointer of new node points to next of temp1
    if(temp1-> next != NULL) temp1->next->prev = temp2; //prev pointer of the node after temp node points to temp2
    temp1->next = temp2; // next pointer of temp1 points to temp2 , so temp2 is inserted between temp1 and the node after temp1

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
    if(head == NULL)
    {
        delete temp;
        return head; //if there's one node and that is deleted head points to null
    }
    head->prev = NULL; //the prev pointer of second will be NULL as the second node is now first node
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
        head = temp1->next; // head becomes NULL
        delete temp1;
        return head;         // in 220 and 226 we check this cases individually as 231 does not cover this cases
    }
    if(temp1->next == NULL) // if there is only one node
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
    temp1->next->prev = temp1; //as middle node is deleted prev pointer now should be pointing to temp1
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
