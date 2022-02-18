#include <bits/stdc++.h>

using namespace std;


bool isMatched(char s, stack<char> s1)
{
    if(s == ')' && s1.top() == '(') return true;

    return false;
}
int main ()
{

    string s;
    stack<char> s1;

    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if(s[i] == ')')
        {

            if(!s1.empty() && isMatched(s[i], s1))
            {
                s1.pop();
            }
            else
            {
                s1.push(s[i]);//if a closing parenthesis found and string is empty then push it
            }


        }
    }
    cout << s1.size() << endl;
    while(!s1.empty())
    {
        s1.pop();
    }

}
