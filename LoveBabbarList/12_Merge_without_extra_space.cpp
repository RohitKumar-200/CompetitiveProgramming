// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        for (int i = n - 1, j = 0; i >= 0 && j < m && arr1[i] > arr2[j]; i--, j++)
            swap(arr1[i], arr2[j]);
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}