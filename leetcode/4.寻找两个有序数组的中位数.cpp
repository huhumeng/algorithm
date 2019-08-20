/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// #include "common.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty())
        {
            int size = nums2.size();

            return size % 2 == 1 ? nums2[size / 2] : 0.5 * (nums2[size / 2] + nums2[size / 2 - 1]);
        }

        if(nums2.empty()){
            int size = nums1.size();
            return size % 2 == 1 ? nums1[size / 2] : 0.5 * (nums1[size / 2] + nums1[size / 2 - 1]);
        }

        int size = nums1.size() + nums2.size();

        if(size % 2 == 1){
            int mid = size / 2;

            int count = 0;


            auto it1 = nums1.cbegin();
            auto it2 = nums2.cbegin();
            double mean;
            while (it1 != nums1.cend() && it2 != nums2.cend())
            {
                if(count == mid){
                    // cout << *it1 << endl;
                    // cout << *it2 << endl;
                    return min(*it1, *it2);
                }
                if(*it1 < *it2)
                {
                    it1++;

                }else
                {
                    it2++;
                }
                
                

                ++count;
            }

            if(it2 == nums2.end()){
                return *(it1 + mid - count);
            }

            if(it1 == nums1.end()){
                return *(it2 + mid - count);
            }
            
        }
        else{

            int mid = size / 2 - 1;

            double median[2];

            double *mean = median;

            int count = 0;


            auto it1 = nums1.cbegin();
            auto it2 = nums2.cbegin();

            // double mean;
            while (it1 != nums1.cend() && it2 != nums2.cend())
            {
                if(count == mid){
                    *mean = min(*it1, *it2);

                    // if(*it1 < *it2){
                    //     *it1
                    // }
                    
                    break;
                }

                if(*it1 < *it2)
                {
                    it1++;

                }else
                {
                    it2++;
                }
                ++count;
            }

            if(it2 == nums2.end()){
                *mean = *(it1 + mid - count);
                median[1] = *(it1 + mid - count + 1);
                return 0.5 * (*mean + median[1]);
            }

            if(it1 == nums1.end()){
                *mean = *(it2 + mid - count);
                median[1] = *(it2 + mid - count + 1);
                return 0.5 * (*mean + median[1]);
            }
// return 0.5 * (*mean + min(*it1, *it2));

            if(*it1 < *it2){
                *it1++;
                if(it1 == nums1.cend())
                    return 0.5 * (*mean + *it2);
                else
                {
                    return 0.5 * (*mean + min(*it1, *it2));
                }
            }else
            {
                it2++;
                if(it2 == nums2.cend())
                    return 0.5 * (*mean + *it1);
                else
                {
                    return 0.5 * (*mean + min(*it1, *it2));
                }
            }
            
            // if(*it1 < *it2){
            //     return 0.5 * (*mean + *it1);
            // }else
            // {
            //     return 0.5 * (*mean + *it2);
            // }
            

            // return *mean;
        }

        return 0.;
    }
};


