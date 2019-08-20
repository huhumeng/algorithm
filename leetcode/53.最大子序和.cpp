/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#ifdef __APPLE__
#include "common.h"
#endif
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = numeric_limits<int>::min();
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {

            if(sum <= 0){
                sum = nums[i];
            }else
            {
                sum += nums[i];
            }
            
            if(sum > max_sum)
                max_sum = sum;
        }

        return max_sum;
    }
};
