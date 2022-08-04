/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include<string>
#include<vector>
// @lc code=start
class Solution {
public:
    bool isIsomorphic(std::string &s, std::string &t) {
        if(s.size() != t.size()){
            return false;
        }

        if (s.empty()){
            return true;
        }
        std::vector<int> s_map(256, 0), t_map(256, 0);
        for(int i = 0; i != s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]]){
                return false;
            }

            s_map[s[i]] = t_map[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end

