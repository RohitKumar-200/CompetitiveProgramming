// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number.
// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i, n = nums.size();
        for (i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                return (nums[i]);
        }
        return -1;
    }
};
