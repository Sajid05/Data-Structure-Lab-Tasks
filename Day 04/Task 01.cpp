#include <bits/stdc++.h>

using namespace std;

int top = -1;


void push(int value, int n, int a[]);

void pop(int a[]);

void display(int a[]);


int main ()
{
    int n, t;
    cout << "Enter size of stack : ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter number of operations : ";
    cin >> t;
    int i, value;
    while (t--)
    {
        cin >> i;
        if (i == 1)
        {
            cin >> value;
            push(value, n, a);
            cout << "size : " << top + 1 << " items : ";
            display(a);
            cout << endl;
        }
        else
        {
            pop(a);
            cout << "size : " << top + 1 << "items : ";
            if (top == -1)
            {
                cout << "NULL" << endl;
            }
            else
            {
                display(a);
                cout << endl;
            }
        }
    }

    return 0;
}


void push(int value, int n, int a[])
{
    if (top == n - 1)
    {
        cout << "Value can not be added" << endl;
    }
    else
    {
        a[++top] = value;
    }
}

void pop(int a[])
{
    if(top == -1)
    {
        cout << "No items to be popped" << endl;
    }
    else
    {
        top--;
    }
}

void display(int a[])
{
    for (int i = 0; i <= top; i++)
        cout << a[i] << " ";
}










