#include <bits/stdc++.h>

using namespace std;


void task1(vector <int> &v1);


int main ()
{
    vector <int> v;
    int take_input;
    while (1)
    {
        cin >> take_input;
        if(take_input < 1)
            break;
        else
            v.push_back(take_input);
    }
    task1(v);


}

void task1(vector <int> &v1)
{
    int i, j, now, x, y;

    vector <int> v2;
    vector <int> v3;


    sort(v1.begin(), v1.end());
    v2.push_back(v1[0]);

    now = 1;
    for(i = 1; i < v1.size(); i++)
    {
        if(v1[i] == v1[i - 1])
            now++;
        else
        {
            v3.push_back(now);
            now = 1;
            v2.push_back(v1[i]);
        }

    }
    v3.push_back(now);


  /*  for(auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
     for(auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
} */
   for (i = 0; i < v3.size() - 1; i++)
    {
        for (j = 0; j < v3.size() - i - 1; j++)
        {
            if (v3[j] < v3[j+1])
            {
                int temp0 = v3[j];
                v3[j] = v3[j + 1];
                v3[j + 1] = temp0;

                int temp = v2[j];
                v2[j] = v2[j + 1];
                v2[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " occurs " << v3[i];
        if (v3[i] == 1) cout << " time \n";
        else cout << " times \n";
    }
}
















