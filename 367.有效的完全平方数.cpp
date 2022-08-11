/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
private:
    int _sqrt_floor(int num){
        float y = num;
        while(y != 1){
            float y_next = (y/2) + (num / (y * 2));
            if(y - y_next <= 0.1){
                break;
            }
            y = y_next;
        }
        return (int)y;
    }

public:
    bool isPerfectSquare(int num) {
        int i = _sqrt_floor(num);
        if(i * i == num){
            return true;
        }
        return false;
    }

};
// @lc code=end

