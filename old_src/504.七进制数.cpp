/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include<string>
// @lc code=start
class Solution {
public:
    std::string convertToBase7(int num) {
        std::string ret;
        int my_num = num>0?num:-num;

        while(my_num!= 0){
            ret.push_back(my_num % 7 + '0');
            my_num = my_num / 7;
        }
        if(ret.empty()){
            ret.push_back('0');
        }
        if(num < 0){
            ret.push_back('-');
        }
        for(int i = 0, j = ret.size() - 1; i < j; i++, j--){
            char temp = ret[i];
            ret[i] = ret[j];
            ret[j] = temp;
        }
        return ret;
    }
};
// @lc code=end

