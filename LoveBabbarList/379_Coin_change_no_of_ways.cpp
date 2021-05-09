// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
// https://practice.geeksforgeeks.org/problems/coin-change2448/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(int S[], int m, int n)
    {
        long long dp[m + 1][n + 1], i, j;
        for (i = 0; i <= m; i++)
            dp[i][0] = 1;
        for (j = 1; j <= n; j++)
            dp[0][j] = 0;

        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
            {
                if (S[i - 1] <= j)
                    dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        return dp[m][n];
    }
};