// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        if (n == 1)
            return 0;
        sort(arr, arr + n);
        int minN = arr[0] + k, maxN = arr[n - 1] - k, i, ans = arr[n - 1] - arr[0];
        if (minN > maxN)
            swap(minN, maxN);
        for (i = 1; i < n - 1; i++)
        {
            int subtract = arr[i] - k;
            int add = arr[i] + k;
            if (subtract >= minN || add <= maxN)
                continue;
            if (maxN - subtract <= add - minN)
                minN = subtract;
            else
                maxN = add;
        }
        return min(ans, maxN - minN);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}