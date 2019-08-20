/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#ifdef __APPLE__
#include "common.h"
#endif
class Solution {
public:

    /**
     * [1 2 3  4 5 6 7 8  9 10 11 12 13 14 15]
     * [0 1 1 1 ]
     */

    int result[16] = {0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3};
    int mySqrt(int x) {

        if(x < 16)
            return result[x];

        unsigned long sq_x = x - 1;

        while (sq_x * sq_x > x)
        {
            sq_x = (sq_x + x / sq_x) / 2;

        }

        return (int)sq_x;
        
    }
};

// int main(){

//     int x;
//     while(cin >> x){
//         cout << Solution().mySqrt(x) << endl;
//     }


//     return 0;
// }
