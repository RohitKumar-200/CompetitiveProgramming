// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1], i, j;
    for (i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (j = 1; j <= y; j++)
        dp[0][j] = 0;

    for (i = 1; i <= x; i++)
        for (j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    return dp[x][y];
}