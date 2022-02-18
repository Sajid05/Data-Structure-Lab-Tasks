#include <bits/stdc++.h>

using namespace std;




int main()
{
    long long int num_of_cookies, sweetness; // for the original problem in hacker rank we had to deal with lli
    cin >> num_of_cookies >> sweetness;
    vector<long long int> v;
    long long int value;
    long long int num_of_operations = 0;
    for(long long int i = 0; i < num_of_cookies; i++)
    {
        cin >> value;
        v.push_back(-1 * value); // we need to check if the least value is greater than sweetness or not.
    // So, we build a max heap with multiplying -1, where front fn returns us the root(max element(here, least value)
    }
    make_heap(v.begin(), v.end());
    if(v.front() * -1 >= sweetness)
    {
        cout << 0 << endl; // if lowest is already greater than sweetness than no operations needed
        return 0;
    }
    else
    {
        long long int leastValue, secondLeastValue;
        long long int sum;
        do
        {


            num_of_operations++;
            leastValue = v.front() * -1;
            pop_heap(v.begin(), v.end()); // After fetching the least value we pop head. So, it goes in the last place of vector
            v.pop_back(); // we discard that least value

            if(v.empty())
            {
                sum = leastValue; //  when no value is left
                break;
            }
            else
            {

                secondLeastValue = v.front() * -1;
                pop_heap(v.begin(), v.end());
                v.pop_back();
            }
            sum = (leastValue * 1) + (secondLeastValue * 2);

            // cout << sum << endl;
            v.push_back(sum * -1); // after discarding two least values, we insert sum in vector as a new ice cream
            push_heap(v.begin(), v.end()); // push heap reorders elements in heap

        }
        while((v.front() * -1) < sweetness);

        if(v.empty()) cout << -1 << endl; // if v is empty then it is not possible to do
        else cout << num_of_operations << endl;
        return 0;
    }
}

