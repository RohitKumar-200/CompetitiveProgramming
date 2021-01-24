// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{

    int localS = arr[0], i, globalS = arr[0];
    for (i = 1; i < n; i++)
    {
        localS = max(arr[i], arr[i] + localS);
        globalS = max(globalS, localS);
    }
    return globalS;
}

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}