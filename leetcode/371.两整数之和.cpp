/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.62%)
 * Total Accepted:    13.8K
 * Total Submissions: 26.7K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */
#if (__GNUC__ == 7 || __GNUC__ == 4)
#include "common.h"
#endif
class Solution {
public:
    int getSum(int a, int b) {

        int c;
        for(;b != 0;){
            c = ((unsigned int)(a & b)) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
#if (__GNUC__ == 7 || __GNUC__ == 4)
int main(){

    int a, b;
    cin >> a >> b;

    cout << Solution().getSum(a, b) << endl;

    return 0;
}

#endif

