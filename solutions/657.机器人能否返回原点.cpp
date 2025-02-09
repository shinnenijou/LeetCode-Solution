/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
#include<unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool judgeCircle(string &moves) {
        std::unordered_map<char, int> moves_count;
        for(int i = 0; i != moves.size(); i++){
            moves_count[moves[i]]++;
        }
        if (moves_count['U'] != moves_count['D'] || moves_count['L'] != moves_count['R'])
            return false;
        
        return true;
    }
};
// @lc code=end

