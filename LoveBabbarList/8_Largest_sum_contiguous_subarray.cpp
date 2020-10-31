// Kadane's Algorithm => Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

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
        int localSum = a[0], globalSum = a[0];
        for (i = 1; i < n; i++)
        {
            localSum = max(a[i], a[i] + localSum);
            globalSum = max(globalSum, localSum);
        }
        cout << globalSum << endl;
    }
    return 0;
}