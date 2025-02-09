/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0) return {};
        vector<vector<int>> ret({{1}});
        for(int i = 1; i != numRows; i++){
            vector<int> row({1});
            for(int j = 1; j != ret.back().size(); j++){
                row.push_back(ret.back()[j] + ret.back()[j - 1]);
            }
            row.push_back(1);
            ret.push_back(row);
        }
        return ret;
    }
};
// @lc code=end

