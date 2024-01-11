/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include<cstdint>
// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t bit_size = sizeof(uint32_t) * 8;
        uint32_t i = 1, j = 1 << (bit_size - 1);
        for(; i != 0; i <<= 1, j >>= 1){
            if(n & j) ret |= i;
        }
        return ret;
    }
};
// @lc code=end

