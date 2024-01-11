/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<vector>
using std::vector;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size() - 1]++;
        carry = digits[digits.size() - 1] / 10;
        digits[digits.size() - 1] %= 10;
        for(int i = digits.size() - 2; i >= 0; i--){
            if(carry){
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
        if(carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};
// @lc code=end

