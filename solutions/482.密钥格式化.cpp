/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */
#include<string>
// @lc code=start
class Solution {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        std::string key;
        int i = 0;
        for(auto iter = s.rbegin(); iter != s.rend(); iter++){
            if(i == k){
                i = 0;
                key.push_back('-');
            }
            if(*iter != '-'){
                char temp = *iter >= 'a' && *iter <= 'z' ? *iter - 'a' + 'A': *iter;
                key.push_back(temp);
                i++;
            }
        }
        if(key.back() == '-') key.pop_back();
        for(int i = 0, j = key.size() - 1; i < j; i++, j--){
            std::swap(key[i], key[j]);
        }
        return key;
    }
};
// @lc code=end

