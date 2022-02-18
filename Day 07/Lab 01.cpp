#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* insertion(Node *current, int data);
void inorder(Node *current);


int Count = 0; //Count keeps track of number of nodes in tree

int main()
{
    int value, no_of_input = 0;
    Node* root = NULL;
    while(1)
    {
        cin >> value;
        if(value == -1) break;
        no_of_input++;
        root = insertion(root, value);
        inorder(root);
        if(Count != no_of_input)
        {
            no_of_input--; // if a reservation fails then that particular input does not count.
            cout << "(Reservation failed)";
        }
        cout << endl;
    }



}

Node* insertion(Node *current, int value)
{
    if(current == NULL)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;

        current = temp;
        Count++; //if a node is formed increase Count
        return current;

    }

    else if(value > current->data && value - current->data > 3)
    {
        current->right = insertion(current->right, value);
    }

    else if((value < current->data && current->data - value > 3))
    {
        current->left = insertion(current->left, value);
    }

    return current;
}

void inorder(Node *current)
{
    if(current == NULL) return;

    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
    return;
}
