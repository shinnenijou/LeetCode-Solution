/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using std::vector; using std::unordered_map;
class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        if(s.empty()) return 0;
        unordered_map<char, int> lastest_index_map;
        vector<int> length_of_LSS(s.size(), 1);
        int max = 1;
        lastest_index_map[s.front()] = 0;
        for(int i = 1; i < s.size(); i++){
            unordered_map<char, int>::iterator iter = lastest_index_map.find(s[i]);
            int lastest_index = 0;
            int head_of_LSS = i - length_of_LSS[i - 1];
            if(iter != lastest_index_map.end()){
                lastest_index = iter->second + 1;
            }
            head_of_LSS = lastest_index > head_of_LSS ? lastest_index : head_of_LSS;
            length_of_LSS[i] = i - head_of_LSS + 1;
            lastest_index_map[s[i]] = i;
            max = length_of_LSS[i] > max ? length_of_LSS[i] : max;
        }
        return max;
    }
};
// @lc code=end

