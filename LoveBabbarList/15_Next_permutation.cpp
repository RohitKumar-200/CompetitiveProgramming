// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order). The replacement must be in place and use only constant extra memory.
// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (!next_permutation(nums.begin(), nums.end()))
            sort(nums.begin(), nums.end());
    }
};

// Another solution using basics
class Solution2
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i, j, l = -1, r = -1, n = nums.size();
        for (i = n - 2; ~i; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                l = i;
                break;
            }
        }
        if (l == -1)
            sort(nums.begin(), nums.end());
        else
        {
            for (i = n - 1; ~i; i--)
            {
                if (nums[i] > nums[l])
                {
                    r = i;
                    break;
                }
            }
            swap(nums[l], nums[r]);
            for (i = l + 1, j = n - 1; i < j; i++, j--)
            {
                swap(nums[i], nums[j]);
            }
        }
    }
};