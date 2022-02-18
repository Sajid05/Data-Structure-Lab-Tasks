#include <bits/stdc++.h>

using namespace std;

int front = -1, rear = -1;

bool isEmpty(int f, int r);
void enqueue(int A[], int size, int value);
void dequeue(int A[], int size);
void display(int A[]);
void circularEnqueue(int A[], int size, int value, int *static_int);
void circularDequeue(int A[], int size, int *static_int);
void circularDisplay(int A[], int size, int *static_int);

int main()
{
    int menu;
    int options;
    do
    {
        front = rear = -1;
        cout << "1. Queue\n2. Circular Queue\n3. Exit" << endl;
        cin >> menu;
        switch(menu)
        {
        case 1: // if any value is dequeued, we can not use that place to store value again until the whole queue is dequeued.
        {
            int size;
            cout << "Enter maximum size of queue : " ;
            cin >> size;
            int *a = new int[size];
            do
            {
                cout << "1. Enqueue\n2. Dequeue\n3. Exit" << endl;
                cin >> options;
                switch(options)
                {
                case 1:
                {
                    int value;
                    cout << "Enter value to be enqueued : " ;
                    cin >> value;
                    enqueue(a, size, value);
                    break;
                }
                case 2:
                {
                    dequeue(a, size);
                    break;
                }
                default:
                    break;
                }

            }
            while(options != 3);
            break;
        }
        case 2:
        {
            int size;
            static int count;
            count = 0;
            cout << "Enter maximum size of queue : " ;
            cin >> size;
            int *a = new int[size];
            do
            {
                cout << "1. Enqueue\n2. Dequeue\n3. Exit" << endl;
                cin >> options;
                switch(options)
                {
                case 1:
                {
                    int value;
                    cout << "Enter value to be enqueued : " ;
                    cin >> value;
                    circularEnqueue(a, size, value, &count);
                    break;
                }
                case 2:
                {
                    circularDequeue(a, size, &count);
                    break;
                }
                default:
                    break;
                }

            }
            while(options != 3);
            break;
        }
        default:
            break;
        }

    }
    while(menu != 3);



    return 0;
}


bool isEmpty()
{
    if (front == -1 && rear == -1) return true;
    return false;
}

void enqueue(int A[], int size, int value)
{
    if(rear == size - 1)
    {
        cout << "Value can not be added!" << endl;
        display(A);
        return;
    }
    else if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    A[rear] = value;
    display(A);
    return;
}

void dequeue(int A[], int size)
{
    if(isEmpty())
    {
        cout << "No items to be removed" << endl;
        return;
    }
    else if(front == rear) // if the last element is deleted, then make the queue reuseable
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    display(A);
    return;
}

void display(int A[])
{

    cout << "Queue : ";
    if(isEmpty()) cout << "Empty" << endl;
    else
    {
        for(int i = front; i <= rear; i++)
        {
            cout << A[i] << " " ;
        }
        cout << endl;
    }
}

void circularEnqueue(int A[], int size, int value, int *static_int)
{
    if((rear + 1) % size == front)
    {
        cout << "Value can not be added!" << endl;
        circularDisplay(A, size, static_int);
        return;
    }
    else if(isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    (*static_int)++;
    cout << endl << "Static Int : " << *static_int << endl;
    A[rear] = value;
    circularDisplay(A, size, static_int);
    return;
}

void circularDequeue(int A[], int size, int *static_int)
{
    if(isEmpty())
    {
        cout << "No items to be removed" << endl;
        return;
    }
    else if(front == rear) // if the last element is deleted, then make the queue empty again
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
    (*static_int)--;
    cout << endl << "Static Int : " << *static_int << endl;
    circularDisplay(A, size, static_int);
    return;
}

void circularDisplay(int A[], int size, int *static_int)
{

    cout << "Queue : ";
    if(isEmpty()) cout << "Empty" << endl;
    else
    {
        if(front > rear)
        {
            int temp = *static_int;
            for(int i = front; i < size; i++)
            {
                cout << A[i] << " ";
                temp--;
               // cout << endl << temp << endl;
            }
            for(int i = 0, j = 1; j <= temp; i++, j++) cout << A[i] << " ";
            cout << endl;
        }
        //if(*static_int <= size)
        //{
        else{
            for(int i = front; i <= rear; i++)
            {
                cout << A[i] << " " ;
            }
            cout << endl;
       // }
        }
    }

}


