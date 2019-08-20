/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// #include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(nums.size() < 2)
            return {};
        map<int, int> answers;

        for(int i=0; i<nums.size(); ++i){
            int other_digits = target - nums[i];
            if(answers.find(other_digits) != answers.end() && answers[other_digits] != i){
                return {i, answers[other_digits]};
            }else
            {
                answers[nums[i]] = i;
            }
            
        }

        
        return {};
    }
};

