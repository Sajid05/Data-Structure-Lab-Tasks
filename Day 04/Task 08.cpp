#include <bits/stdc++.h>

using namespace std;

stack<int> reverseStack(stack <int> *s)
{
    stack<int> temp;
    while(!s->empty())
    {
        temp.push(s->top());
        s->pop();
    }
    return temp;
}


int main()
{

    int number_of_trucks;
    while (1)
    {
        stack<int> s;
        int val;
        cin >> number_of_trucks;
        if(number_of_trucks == 0) break; // keep taking test cases till 0 is encountered
        for(int i = 0; i < number_of_trucks; i++)
        {
            cin >> val;
            if(val == 0) break;
            s.push(val);
        }
        s = reverseStack(&s); // reverse the
        int initial = 1, count = 0;
        stack<int> temp;
        while(1)
        {
            if(count == number_of_trucks)
            {
                cout << "yes" << endl;
                break;
            }

            if(s.empty() && temp.top() != initial)
            {
                cout << "no" << endl;
                break;
            }



            if(!s.empty() && s.top() == initial)
            {
                initial++;
                s.pop();
                count++;
            }



            else if(!temp.empty() && temp.top() == initial)
            {
                initial++;
                temp.pop();
                count++;
            }


            else
            {
                temp.push(s.top());
                s.pop();
            }
        }

        while(!temp.empty())
        {
            temp.pop();
        }
    }
}









