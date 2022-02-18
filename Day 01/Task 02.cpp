#include <bits/stdc++.h>

using namespace std;

int recursion (int n)
{
    if (n < 1) return 1;
    return n * recursion(n - 1);
}


int main()
{
    int input;
    cin >> input;
    int ans;
    ans = recursion(input);
    cout << ans;
    return 0;
}
