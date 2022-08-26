/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */
#include<unordered_map>
#include<vector>
#include<string>
// @lc code=start
class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::vector<std::string> ret;
        std::unordered_map<char, int> char_map;
        for(char c : std::string("qwertyuiop")){
            char_map[c] = 1;
            char_map[c - 'a' + 'A'] = 1;
        }

        for(char c : std::string("asdfghjkl")){
            char_map[c] = 2;
            char_map[c - 'a' + 'A'] = 2;
        }

        for(char c : std::string("zxcvbnm")){
            char_map[c] = 3;
            char_map[c - 'a' + 'A'] = 3;
        }

        for(auto iter = words.begin(); iter != words.end(); iter++){
            int prev = char_map[iter->front()];
            bool in_a_row = true;
            for(char c : *iter){
                if(prev != char_map[c]){
                    in_a_row = false;
                    break;
                }
                prev = char_map[c];
            }
            if(in_a_row){
                ret.push_back(*iter);
            }
        }

        return ret;
    }
};
// @lc code=end

