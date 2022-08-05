/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include<string>
#include<sstream>
#include<unordered_map>
// @lc code=start
class Solution {
public:
    bool wordPattern(std::string &pattern, std::string &s) {
        std::istringstream sstream(s);
        std::string word;
        std::unordered_map<char, std::string> p_map;
        std::unordered_map<std::string, char> s_map;
        int i = 0;
        while(i != pattern.size() && sstream >> word){
            if(p_map.find(pattern[i]) == p_map.end() && s_map.find(word) == s_map.end()){
                p_map[pattern[i]] = word;
                s_map[word] = pattern[i];       
            }
            else if(p_map.find(pattern[i]) != p_map.end() && s_map.find(word) != s_map.end()){
                if(p_map[pattern[i]] != word or s_map[word] != pattern[i]){
                    return false;
                }
            }
            else{
                return false;
            }
            i++;
        }

        if(sstream >> word or i != pattern.size()){
            return false;
        }

        return true;
    }
};
// @lc code=end

