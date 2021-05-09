// Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        int n = str.length();
        int dp[n + 1][n + 1], i, j;
        for (i = 0; i <= n; i++)
            dp[i][0] = 0, dp[0][i] = 0;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (str[i - 1] == str[j - 1] && i != j)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[n][n];
    }
};