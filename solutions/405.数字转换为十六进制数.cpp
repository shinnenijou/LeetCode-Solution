/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include<string>

// @lc code=start
class Solution {
public:
    std::string toHex(int num) {
        std::string ret;
        int mask = 0xF;
        for(int i = 0; i != sizeof(int) << 1; i++){
            int temp_num = num & mask;
            temp_num = temp_num < 10?temp_num + '0':temp_num - 10 + 'a';
            ret.push_back(temp_num);
            num >>= 4;
        }
        while(!ret.empty() && ret.back() == '0'){
            ret.pop_back();
        }
        for(int i = 0, j = ret.size() - 1; i < j; i++, j--){
            std::swap(ret[i], ret[j]);
        }
        if(ret.empty()){
            ret.push_back('0');
        }
        return ret;
    }
};
// @lc code=end

