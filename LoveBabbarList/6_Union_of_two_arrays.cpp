// Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays
// https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int t;
    for (cin >> t; t--;)
    {
        int n, m, i, j, c = -1;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < m; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);
        for (i = 0, j = 0; i < n + 1 && j < m + 1;)
        {
            while (i && a[i] == a[i - 1])
                i++;
            while (j && b[j] == b[j - 1])
                j++;
            if (a[i] < b[j])
                i++, c++;
            else if (a[i] > b[j])
                j++, c++;
            else
                i++, j++, c++;
        }
        cout << c << endl;
    }
    return 0;
}