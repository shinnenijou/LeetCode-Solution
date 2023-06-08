/*
 * 剑指 Offer 10- II. 青蛙跳台阶问题
 */

// @lc code=start
class Solution {
public:
    int numWays(int n) {
        int an[3] = {1, 1, 0};
        if(n < 2) return an[n];
        for(int i = 1; i < n; ++i){
            an[2] = (an[1] + an[0]) % 1000000007;
            an[0] = an[1];
            an[1] = an[2];
        } 
        return an[2];
    }
};
// @lc code=end
