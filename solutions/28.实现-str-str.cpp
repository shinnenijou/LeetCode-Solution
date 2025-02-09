/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
    vector<int> _build_LPS(string &pattern)
    {
        vector<int> lps(pattern.size(), 0);
        int pref_i = 0;
        for (int i = 1; i < pattern.size(); i++)
        {
            while (pref_i && pattern[i] != pattern[pref_i])
            {
                pref_i = lps[pref_i - 1];
            }

            if (pattern[i] == pattern[pref_i])
            {
                pref_i++;
                lps[i] = pref_i;
            }
        }
        return lps;
    }

public:
    int strStr(string &haystack, string &needle)
    {
        vector<int> lps = _build_LPS(needle);
        int haystack_i = 0, needle_i = 0;
        for (; haystack_i != haystack.size(); haystack_i++)
        {
            while (needle_i && haystack[haystack_i] != needle[needle_i])
            {
                needle_i = lps[needle_i - 1];
            }

            if (haystack[haystack_i] == needle[needle_i])
            {
                if (needle_i == needle.size() - 1)
                {
                    return haystack_i - needle_i;
                }
                else
                {
                    needle_i++;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
