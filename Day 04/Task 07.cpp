#include <bits/stdc++.h>

using namespace std;

bool isOpeningParenthesis(char c);
bool isClosingParenthesis(char c);
bool isOperator(char c);
bool hasHigherPrecedence(char c1, char c2);

int main ()
{
    int t;
    cin >> t;
    string s;
    string result;
    stack <char> s1;
    while (t--)
    {
        cin >> s;
        int length = s.size();

        for (int i = 0; i < length; i++)
        {
            if(isalpha(s[i]))
            {

                result.push_back(s[i]); // is alphabet found then directly insert in result
            }

            else if(isOperator(s[i]))
            {
                while(!s1.empty() && hasHigherPrecedence(s1.top(), s[i]) && !isOpeningParenthesis(s1.top()))
                {
                    result.push_back(s1.top()); //if an operator found with lower precedence then continue to pop from
                    s1.pop();                   //the stack until the stack is empty or operator with lower precedence found or
                }                               // an opening parenthesis is found
                s1.push(s[i]); //insert all operators in stack
            }
            else if (isOpeningParenthesis(s[i]))
            {
                s1.push(s[i]);
            }
            else if(isClosingParenthesis(s[i]))
            {
                while(!s1.empty() && !isOpeningParenthesis(s1.top()))
                {
                    result.push_back(s1.top()); //when closing parenthesis found then insert all the operators in result
                    s1.pop();                   // until an opening parenthesis is found
                }
                s1.pop();  //do an extra pop to pop the opening parenthesis
            }
        }


        while(!s1.empty()) //if no parenthesis is left, then insert the remaining operators in result
        {
            result = result + s1.top();
            s1.pop();
        }

        cout << result << endl;
        result.clear(); // clear result before moving to another test case

    }

}



bool isOpeningParenthesis(char c)
{
    if(c == '(')
        return true;
    return false;
}

bool isClosingParenthesis(char c)
{
    if(c == ')')
        return true;
    return false;
}

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

bool hasHigherPrecedence(char c1, char c2)
{
    if (c1 == '+') c1 = 10;
    else if (c1 == '-') c1 = 10;
    else if (c1 == '*') c1 = 20;
    else if (c1 == '/') c1 = 20;
    else if (c1 == '^') c1 = 30;

    if (c2 == '+') c2 = 10;
    else if (c2 == '-') c2 = 10;
    else if (c2 == '*') c2 = 20;
    else if (c2 == '/') c2 = 20;
    else if (c2 == '^') c2 = 30;

    if(c1 >= c2) return true;
    return false;

}
