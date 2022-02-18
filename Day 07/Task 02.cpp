#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* insertion(Node *current, int data);
void leverlOrderTraversal(Node *root);


int main()
{
    int value, no_of_input = 0;
    Node* root = NULL;
    while(1)
    {
        cin >> value;
        if(value == -1) break;
        root = insertion(root, value);

    }
    leverlOrderTraversal(root);



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

void leverlOrderTraversal(Node *root)
{
    if(root == NULL) return;


    queue <Node*> q1; // queue stores the Node pointers
    q1.push(root); //initially q1 only has pointer pointing towards root

    while(!q1.empty()) //as long as q1 is not empty tree in not finished
    {
        cout << q1.front()->data << " ";
        if(q1.front()->left != NULL) // in first iteration if root's left pointer pointing towards something/ have left child then add that pointer to left child to queue
            q1.push(q1.front()->left);
        if(q1.front()->right != NULL)
            q1.push(q1.front()->right);
        q1.pop(); // in each iteration perform a pop to remove that corresponding node pointer from queue
    }
    return;
}
