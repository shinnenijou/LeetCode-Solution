/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
#include<vector>
class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat.front().size(), num_count = m * n;
        if(num_count != r * c) return mat;
        std::vector<std::vector<int>> ret(r, std::vector<int>(c));
        for(int i = 0; i != num_count; i++){
            ret[i / c][i % c] = mat[i /n][i % n];
        }
        return ret;
    }
};
// @lc code=end

