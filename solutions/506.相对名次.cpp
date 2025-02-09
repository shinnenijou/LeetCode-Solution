/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */
#include<string>
#include<vector>
#include<map>
// @lc code=start
class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<std::string> medals({"Gold Medal", "Silver Medal", "Bronze Medal"});
        std::map<int, std::string, std::greater<int>> rank_map;
        for(int i = 0; i != score.size(); i++){
            rank_map[score[i]] = std::string(""); 
        }
        auto iter = rank_map.begin(), iter_begin = rank_map.begin();
        int i = 0;
        for(; i != medals.size() && iter != rank_map.end(); iter++){
            rank_map[iter->first] = medals[i++];
        }
        for(; iter != rank_map.end(); iter++){
            rank_map[iter->first] = std::to_string(1 + i++);
        }

        std::vector<std::string> ret;
        for(i = 0; i != score.size(); i++){
            ret.push_back(rank_map[score[i]]);
        }
        return ret;
    }
};
// @lc code=end

