/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */
// @lc code=start

#include<climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ret = m * n;
        int min_a = INT_MAX, min_b = INT_MAX;
        for(int i = 0; i != ops.size(); i++){
            min_a = ops[i][0] < min_a ? ops[i][0] : min_a;
            min_b = ops[i][1] < min_b ? ops[i][1] : min_b;
        }
        if(min_a != INT_MAX && min_b != INT_MAX) ret = min_a * min_b;
        return ret;
    }
};
// @lc code=end

