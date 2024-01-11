/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */
#include<cmath>
#include<vector>
// @lc code=start
class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        std::vector<int> ret;
        int w = std::sqrt(area);
        while(area % w != 0){
            w--;
        }
        ret.push_back(area / w);
        ret.push_back(w);
        return ret;
    }
};
// @lc code=end

