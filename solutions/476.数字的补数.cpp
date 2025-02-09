/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */
#include<climits>
// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        unsigned int temp = num;
        int cnt = sizeof(int) << 3;
        while(!(temp & INT_MIN)){
            cnt--;
            temp <<= 1;
        }
        unsigned mask = ~(UINT_MAX << (cnt - 1));
        return (int)~num & mask;
    }
};
// @lc code=end

