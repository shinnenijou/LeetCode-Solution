/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include<vector>
// @lc code=start
class Solution {
    int _popcount(int n){
        int count = 0;
        while(n){
            n &= n - 1;
            count++;
        }
        return count;
    }
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ret;
        for(int i = 0; i != n + 1; i++){
            ret.push_back(_popcount(i));
        }
        return ret;
    }
};
// @lc code=end

