#include <bits/stdc++.h>

using namespace std;


void display(stack<int> s);

int main ()
{
    int n, t;
    stack <int> s;
    cout << "Enter size of stack : ";
    cin >> n;
    //int *a = new int[n];
    cout << "Enter number of operations : ";
    cin >> t;
    int i, value;
    while (t--)
    {
        cin >> i;
        if (i == 1)
        {
            cin >> value;
            if( s.size() == n)
            {
                cout << "Value can not be added" << endl;
            }
            else s.push(value);



            cout << "size : " << s.size() << " items : ";
            display(s);
            cout << endl;

        }
        else
        {

            if (s.size() == 0)
                cout << "size : " << 0 << " items : NULL";
            else
            {

                s.pop();
                if (s.size() == 0)
                {
                    cout << "size : " << 0 << " items : NULL";
                }
                else
                {
                    cout << "size : " << s.size() << " items :";
                    display(s);
                }
            }
            cout << endl;

        }
    }
}

void display(stack<int> s)
{
    stack<int> s1;
    int Length = s.size();
    for (int i = 0; i < Length; i++)
    {
        s1.push(s.top());
        s.pop();
    }
    for (int i = 0; i < Length; i++)
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}










