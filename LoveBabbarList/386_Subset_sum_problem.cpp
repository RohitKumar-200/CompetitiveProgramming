// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int N, int sum)
{
    bool dp[N + 1][sum + 1];

    for (int i = 0; i < N + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1)
            return 0;
        else
            return subsetSum(arr, N, sum / 2);
    }
};