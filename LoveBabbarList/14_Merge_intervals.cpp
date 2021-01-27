// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

// Solution O(n)
class Solution1
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int a[100000] = {0}, n = 0, c = 0, l, single[100000] = {0};
        // a is to store range of intervals and single is to store only single points
        vector<vector<int>> ans;
        for (auto it : intervals)
        {
            if (it[0] == it[1])
                single[it[0]] = -1;
            a[it[0]]++;
            a[it[1]]--;
            n = max(n, it[1]);
        }
        for (int i = 0; i <= n; i++)
        {
            if (c == 0 && a[i] > 0)
            {
                l = i;
            }
            c += a[i];
            if (c == 0 && a[i] < 0)
            {
                ans.push_back({l, i});
                single[l] = i;
                single[i] = i + 1;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (single[i] > 0)
            {
                i = single[i] - 1;
                continue;
            }
            if (single[i] == -1)
                ans.push_back({i, i});
        }
        return ans;
    }
};

// Solution O(nlog(n))
class Solution2
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l = -1, r = -1;
        for (auto it : intervals)
        {
            if (l == -1)
            {
                l = it[0];
                r = it[1];
            }
            else if (r >= it[0])
            {
                r = max(r, it[1]);
            }
            else
            {
                ans.push_back({l, r});
                l = it[0], r = it[1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};