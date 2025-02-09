/*
 * 剑指 Offer 10- I. 斐波那契数列
 */

// @lc code=start
class Solution {
private:
    int m_mod = 1000000007;
public:
    int fib(int n) {
        if (n == 0)
        {
            return 0;
        }

        int a = 0;
        int b = 1;
        int ret = 1;

        for(int i = 2; i <= n; ++i){
            ret = (a + b) % m_mod;
            a = b;
            b = ret;
        }

        return ret;
    }
};
// @lc code=end
