/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
private:
    int _clamp_minus(int *map, char c1, char c2)
    {
        int ret = map[c1 - 'A'];
        switch (c1)
        {
        case 'I':
            if (c2 == 'V' || c2 == 'X')
            {
                ret = -ret;
            }
            break;
        case 'X':
            if (c2 == 'L' || c2 == 'C')
            {
                ret = -ret;
            }
            break;
        case 'C':
            if (c2 == 'D' || c2 == 'M')
            {
                ret = -ret;
            }
            break;
        }
        return ret;
    }

public:
    int romanToInt(string &s)
    {
        // std::unordered_map<char, int> char_to_int_map({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        int char_to_int_map[26];
        char_to_int_map['I' - 'A'] = 1;
        char_to_int_map['V' - 'A'] = 5;
        char_to_int_map['X' - 'A'] = 10;
        char_to_int_map['L' - 'A'] = 50;
        char_to_int_map['C' - 'A'] = 100;
        char_to_int_map['D' - 'A'] = 500;
        char_to_int_map['M' - 'A'] = 1000;
        int sum = 0;
        for(int i = 0; i < s.size() - 1; i++){
            sum += _clamp_minus(char_to_int_map, s[i], s[i + 1]);
        }
        sum += char_to_int_map[s.back() - 'A'];
        return sum;
    }
};
// @lc code=end
