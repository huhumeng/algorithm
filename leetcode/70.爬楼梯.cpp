/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3){
            return n;
        }

        int prev = 2;
        int last = 3;

        for(int i = 4; i <= n; ++i){
            int curr = prev + last;
            prev = last;
            last = curr;
        }
        
        return last;
    }
};

