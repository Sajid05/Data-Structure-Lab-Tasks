//Done with help

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    int val;
    int arraySize = 0;
    while (t--)
    {
        arraySize = 0;
        int a[10000];
        while (1)
        {
            cin >> val;
            if(val == -1) break;
            else
            {
                a[arraySize++] = val;
            }
        }

        stack<int> finalAns;
        stack<int> temp;
        for(int i = arraySize - 1; i >= 0; i--)
        {
            while(!temp.empty() && a[i] >= temp.top())
            {
                temp.pop(); // if the top value is less than current value that means it can't be the NGE
            }

            if(temp.empty()) finalAns.push(-1); // When there is no element ( in case of the greatest element array becomes empty)
            else finalAns.push(temp.top()); // The top value is the NGE for current value

            temp.push(a[i]); // Insert every value in stack
        }


        while(!finalAns.empty())
        {
            cout << finalAns.top() << " ";
            finalAns.pop();
        }

        cout << endl;
    }
}
