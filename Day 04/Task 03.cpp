#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    string s;
    stack<char> s1;
    while(t--)
    {
        cin >> s;
        for(int i = 0; i < s.size(); i++)
        {
            s1.push(s[i]);
        }
        for(int i = 0; i < s.size(); i++)
        {
            cout << s1.top() ;
            s1.pop();
        }
        cout << endl;
    }
}
