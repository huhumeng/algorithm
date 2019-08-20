/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#ifdef __APPLE__
#include "common.h"
#endif 
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        for(auto it = s.begin(); it != s.end(); ++it){

            if(*it == 'I')
            {
                if((it + 1) == s.end()){
                    result += 1;
                    break;
                }else if(*(it + 1) == 'V'){
                    it++;
                    result += 4;
                    continue;
                }else if(*(it + 1) == 'X'){
                    it++;
                    result += 9;
                    continue;
                }else
                {
                    result += 1;
                    continue;
                }
            }

            if(*it == 'V'){
                result += 5;
                continue;
            }

            if(*it == 'X')
            {
                if((it + 1) == s.end()){
                    result += 10;
                    break;
                }else if(*(it + 1) == 'L'){
                    it++;
                    result += 40;
                    continue;
                }else if(*(it + 1) == 'C'){
                    it++;
                    result += 90;
                    continue;
                }else
                {
                    result += 10;
                    continue;
                }
            }

            if(*it == 'L'){
                result += 50;
                continue;
            }

            if(*it == 'C')
            {
                if((it + 1) == s.end()){
                    result += 100;
                    break;
                }else if(*(it + 1) == 'D'){
                    it++;
                    result += 400;
                    continue;
                }else if(*(it + 1) == 'M'){
                    it++;
                    result += 900;
                    continue;
                }else
                {
                    result += 100;
                    continue;
                }
            }

            if(*it == 'D'){
                result += 500;
                continue;
            }

            if(*it == 'M'){
                result += 1000;
                continue;
            }

        }

        return result;
    }
};

// int main(){

//     string s;
//     while(cin >> s)
//         cout << Solution().romanToInt(s) << endl;

//     return 0;
// }
