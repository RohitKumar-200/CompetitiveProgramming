// Given a sequence, find the length of the longest palindromic subsequence in it.
// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1], i, j;
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (j = 1; j <= n; j++)
        dp[0][j] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    return dp[m][n];
}

int main()
{
    string s;
    cin >> s;
    string revS = s;
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        swap(s[i], s[j]);
    cout << LCS(s, revS) << '\n';
}