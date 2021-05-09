// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications. The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int multiplicationCost(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempAns = multiplicationCost(arr, i, k) + multiplicationCost(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, tempAns);
    }
    return dp[i][j] = ans;
}

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return multiplicationCost(arr, 1, N - 1);
    }
};