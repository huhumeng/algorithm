/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.01%)
 * Total Accepted:    62K
 * Total Submissions: 137.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

#if (__GNUC__ == 7 ||  __GNUC__ == 4)
#include "common.h"
#endif

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n == 0)
            return;
        auto it1 = nums1.cbegin() + m - 1;
        auto it2 = nums2.cbegin() + n - 1;

        auto it3 = nums1.begin() + m + n - 1;

        while(it1 >= nums1.cbegin() && it2 >= nums2.cbegin()){
            
            // cout << "it1 = " << *it1 << " it2 = " << *it2 << endl;
            
            if(*it1 < *it2){
                *it3 = *it2;
                --it3;
                --it2;
            }else{
                *it3 = *it1;
                --it3;
                --it1;
            }
        }

        if(it1 >= nums1.cbegin()){
            return;
        }else{
            it3 = nums1.begin();
            for(auto it = nums2.begin(); it <= it2; ++it, ++it3){
                *it3 = *it;
            }
        }
    }
};


#if (__GNUC__ == 7 ||  __GNUC__ == 4)
int main(){

    vector<int> v1 = {1};
    vector<int> v2 = {0};

    Solution().merge(v1, 1, v2, 0);

    cout << v1 << endl;

    return 0;
}

#endif

