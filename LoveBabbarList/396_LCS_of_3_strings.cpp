// Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.
// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1 + 1][n2 + 1][n3 + 1], i, j, k;

    for (i = 0; i <= n1; i++)
    {
        for (j = 0; j <= n2; j++)
        {
            for (k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }

    return dp[n1][n2][n3];
}