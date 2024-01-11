/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
#include<string>
#include<unordered_map>
class Solution {
private:
    int m_sum_A = 0;
    int m_continuous_L = 0;
    static void _handle_A(Solution &s){s.m_sum_A++; s.m_continuous_L = 0;}
    static void _handle_L(Solution &s){s.m_continuous_L++;}
    static void _handle_P(Solution &s){s.m_continuous_L = 0;}
public:
    bool checkRecord(std::string &s) {
        void (*handlers[3])(Solution &) = {
            _handle_A, _handle_L, _handle_P
        };
        std::unordered_map<char, int> func_map;
        func_map['A'] = 0, func_map['L'] = 1, func_map['P'] = 2;
        for(int i = 0; i != s.size() && m_sum_A < 2 && m_continuous_L < 3; i++){
            handlers[func_map[s[i]]](*this);
        }
        if(m_sum_A >= 2 or m_continuous_L >= 3) return false;
        return true;
    }
};
// @lc code=end

