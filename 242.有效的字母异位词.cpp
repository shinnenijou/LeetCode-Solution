/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include<string>
#include<unordered_map>
// @lc code=start
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()){
            return false;
        }

        std::unordered_map<int, int> s_map, t_map;
        for(int i = 0; i != s.size(); i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        if(s_map.size() != t_map.size()){
            return false;
        }

        for(auto s_iter = s_map.begin(); s_iter != s_map.end(); s_iter++){
            auto t_iter = t_map.find(s_iter->first);
            if(t_iter == t_map.end() || t_iter->second != s_iter->second){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

