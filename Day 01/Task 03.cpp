#include <bits/stdc++.h>

using namespace std;



int bsiteraitve(int A[], int n, int check);

int bsrecursive (int A[], int l, int h, int check);


int main()
{

    int A[10000];
    int i = 0;
    int k;
    for(i = 0; ; i++)
    {
        cin >> k;
        if(k < 1) break;
        A[i] = k;
    }
    int input;
    cin >> input;

    cout << "1. Iterative " << "\n" << "2. Recursive" << "\n";

    int c, ans;
    cin >> c;
    switch(c)
    {
    case 1:
        ans = bsiteraitve(A, i, input);
        break;
    case 2:
        ans = bsrecursive(A, 0, i - 1, input);
        break;
    default:
        ans = bsiteraitve(A, i, input);

    }

    cout << ans;
    return 0;


}





int bsiteraitve(int A[], int n, int check)
{
    int l, h, mid;
    l = 0, h = n - 1;
    for( ; l <= h ; )
    {
        mid = (l + h) / 2;
        if (A[mid] == check)
                return mid;
        else if(A[mid] < check)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }


    return -1;

}


int bsrecursive (int A[], int l, int h,  int check)
{
    int mid = (l + h) / 2;
    if(A[mid] == check) return mid;
    if(l > h) return -1;


    if(A[mid] > check) bsrecursive(A, l, mid - 1, check);
    else bsrecursive(A, mid + 1, h, check);
}








