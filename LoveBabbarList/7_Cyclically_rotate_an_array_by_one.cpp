// Given an array, cyclically rotate an array by one
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int t;
    for (cin >> t; t--;)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        int last = a[n - 1];
        for (i = n - 1; ~i; i--)
            a[i] = a[i - 1];
        a[0] = last;
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}