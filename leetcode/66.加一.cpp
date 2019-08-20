/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#ifdef __APPLE__
#include "common.h"
#endif
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        if(digits.back() != 9){
            digits.back() += 1;
            return digits;
        }
        else
        {   
            auto it=digits.rbegin();
            for(; it != digits.rend() && *it==9; ++it){
                *it = 0;
            }
            
            if(it == digits.rend()){
                vector<int> ret(digits.size() + 1, 0);
                ret.front() = 1;
                return ret;
            }
            else
            {
                *it += 1;
            }
            
            return digits;
        }
        
    }
};
// int main()
// {   
    

//     vector<int> nums;
//     int num1, num2, num3;
//     scanf("%d %d %d", &num1, &num2, &num3);
//     nums.push_back(num1);
//     nums.push_back(num2);
//     nums.push_back(num3);

//     for(auto it = nums.rbegin(); it != nums.rend(); ++it){
//         cout << *it << " ";
//     }
//     cout << endl;

//     cout << Solution().plusOne(nums) << endl;

//     return 0;
// }
