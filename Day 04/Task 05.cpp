#include <bits/stdc++.h>

using namespace std;

bool isOpeningParenthesis(char c)
{
    if(c == '(' || c == '{' || c =='[')
        return true;
    return false;
}

bool isClosingParenthesis(char c)
{
    if(c == ')' || c == '}' || c ==']')
        return true;
    return false;
}

bool isMatched(char s, stack<char> s1)
{
    if(s == ')' && s1.top() == '(') return true;
    else if (s == '}' && s1.top() == '{') return true;
    else if (s == ']' && s1.top() == '[') return true;

    return false;
}
int main ()
{
    int t;
    string s;
    cin >> t;
    getchar();
    stack<char> s1;
    while (t--)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            if (isOpeningParenthesis(s[i]))
            {
                s1.push(s[i]);
            }
            else if(isClosingParenthesis(s[i]))
            {

                if(isMatched(s[i], s1))
                {
                    s1.pop();
                }

            }
        }
        if(s1.empty())
        {
            cout << "Yes"  << endl;
        }
        else
        {
            cout << "No" << endl;
            while(!s1.empty())
                s1.pop();

        }
    }
}
