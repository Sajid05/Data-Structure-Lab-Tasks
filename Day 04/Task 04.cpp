#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    string s;
    stack<int> s1;
    int op1;
    int op2;
    while(t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 48 && s[i] <= 57)
                s1.push(s[i] - 48);
            else
            {
                op2 = s1.top() ;
                s1.pop();
                op1 = s1.top() ;
                s1.pop();
                if (s[i] == '+')
                {
                    s1.push(op1 + op2);
                }
                else if(s[i] == '-')
                {
                    s1.push(op1 - op2);
                }
                else if(s[i] == '*')
                {
                    s1.push(op1 * op2);
                }
                else if(s[i] == '/')
                {
                    s1.push(op1 / op2);
                }
            }
        }
        cout << s1.top() << endl;
        s1.pop();
    }
}
