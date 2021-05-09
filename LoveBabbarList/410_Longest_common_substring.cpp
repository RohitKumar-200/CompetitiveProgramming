// Given two strings. The task is to find the length of the longest common substring.
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int dp[n + 1][m + 1], i, j;
        for (i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (j = 1; j <= m; j++)
            dp[0][j] = 0;

        int ans = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        return ans;
    }
};