// Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int c = 0, ans = 0, i;
    while (c < n - 1)
    {
        if (arr[c] == 0)
            return -1;
        if (c + arr[c] >= n - 1)
        {
            ans++;
            break;
        }
        pair<int, int> p = {-1, -1}; // p.first = maxValue, p.second = index of maxValue
        for (i = c + 1; i < n && i <= c + arr[c]; i++)
        {
            if (i - c + arr[i] >= p.first)
                p.first = i - c + arr[i], p.second = i;
        }
        ans++;
        c = p.second;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}