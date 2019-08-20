/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#ifdef __APPLE__
#include "common.h"
#endif
class Solution {
public:
    string addBinary(string a, string b) {
        auto ita = a.rbegin();
        auto itb = b.rbegin();

        auto size = max(a.size(), b.size());

        char result[size + 2];
        result[size + 1] = '\0';

        char add = 0;

        while (ita != a.rend() && itb != b.rend())
        {
            char bit = *ita + *itb + add - '0';


            if(bit > 49){
                result[size] = bit - 2;
                add = 1;
            }else
            {
                result[size] = bit;
                add = 0;
            }
            
            --size;

            ++ita;
            ++itb;
        }
        
        while (ita != a.rend())
        {
            char bit = *ita + add;

            if(bit > 49){
                result[size] = bit - 2;
                add = 1;
            }else
            {
                result[size] = bit;
                add = 0;
            }
            --size;
            ++ita;
        }

        
        
        while (itb != b.rend())
        {
            char bit = *itb + add;
            if(bit > 49){
                result[size] = bit - 2;
                add = 1;
            }else
            {
                result[size] = bit;
                add = 0;
            }
            --size;
            ++itb;
        }

        // assert(size == 0);
       
        if(add == 1){
            result[0] = '1';
            return string(result);
        }else{
            return string(result + 1);
        }
    }
};

// int main()
// {

//     cout << Solution().addBinary("11", "1") << endl;

//     return 0;
// }

