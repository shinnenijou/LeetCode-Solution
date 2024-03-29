/*
 * 剑指 Offer 05. 替换空格
 */

// @lc code=start
#include<string>
using std::string;

class Solution {
public:
    string replaceSpace(string &s) {
        string ret;
        for(int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                ret.push_back('%');
                ret.push_back('2');
                ret.push_back('0');
            }
            else
            {
                ret.push_back(s[i]);
            }
        }

        return ret;
    }
};
// @lc code=end
