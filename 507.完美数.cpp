/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */
#include<cmath>
// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sqrt_num = std::sqrt(num);
        int sum = 1;
        for(int i = 2; i <= sqrt_num; i++){
            if(num % i == 0){
                sum += i + num / i;
            }
        }
        return sum == num;
    }
};
// @lc code=end

