/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        
        size_t size = s.size();

        if(size == 0){
            return 0;
        }
        if(size == 1){
            return 1;
        }

        int maxlen = 0;
        int len = 0;
        int i, j;
        for(i=0; i<size; ){
            for(j=i; j<size; ){
                if(addchar(s[j]))
                {
                    ++len;
                    ++j;
                }else{
                    maxlen = max(len, maxlen);
                    
                    len = 0;
                    memset(mappp, 0, map_size);
                    i = j;
                    break;
                }
                
                
            }
        }


        return maxlen;

    }

    bool addchar(char c){
        if(mappp[c])
            return false;
        
        mappp[c] = true;
        return true;
    }

    bool mappp[256] = {0};

    static constexpr int map_size = sizeof(bool) * 256;
};

