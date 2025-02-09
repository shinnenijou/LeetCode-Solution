/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<string>
using std::string;
class Solution {
public:
    string addBinary(string &a, string &b) {
        string &shorter = a.size() < b.size()?a:b;
        string &longer = a.size() < b.size()?b:a;
        int i = longer.size() - 1, j = shorter.size() - 1;
        int carry = 0;
        string ret(longer);
        for(; i >= 0 && j >= 0; i--, j--){
            char digit = longer[i] - '0' + shorter[j] - '0' + carry;
            carry = digit >> 1;
            ret[i] = (digit & 1) + '0';
        }
        for(; i >= 0; i--){
            char digit = longer[i] - '0' + carry;
            carry = digit >> 1;
            ret[i] = (digit & 1) + '0';
        }
        if(carry) ret.insert(ret.begin(), carry + '0');
        
        return ret;
    }
};
// @lc code=end

