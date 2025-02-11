#include "catch_amalgamated.hpp"
#include <string>
#include <vector>
using namespace std;


// Manacher algorithm
// see: https://cp-algorithms.com/string/manacher.html
class LongestPalindromicSubstringManacher
{
public:
    string longestPalindrome(const string& s)
    {
        // for pos i, [i - d[i], i + d[i]] is a palindrome
        vector<int> d(size(s));

        // [l, r] right-most palindrome substring. initial at s[0]
        int l = 0, r = 0;
        int maxIndex = 0;
        int maxLen = 0;

        for (int i = 1; i < size(s); ++i)
        {
            if (i > r)
            {
                d[i] = bruteForce(s, i, 1);
            }
            else if (i + d[l + r - i] >= r)
            {
                d[i] = bruteForce(s, i, r - i + 1);
            }
            else
            {
                d[i] = d[l + r - i];
            }

            if (i + d[i] > r)
            {
                r = i + d[i];
                l = i - d[i];
            }

            if (d[i] > maxLen)
            {
                maxLen = d[i];
                maxIndex = i;
            }
        }

        // real string
        return s.substr((maxIndex >> 1) - (maxLen >> 1), maxLen);
    }

private:
    static char charAt(const string& s, const int i)
    {
        return i & 1 ? s[i >> 1] : static_cast<char>(0xFF);
    }

    static int size(const string& s) { return (s.size() << 1) + 1; }

    static int bruteForce(const string& s, const int pos, int length)
    {
        while (pos - length >= 0 && pos + length < size(s) && charAt(s, pos - length) == charAt(s, pos + length)) ++
            length;
        return length - 1;
    }
};

TEST_CASE("LongestPalindromicSubstringManacher", "[LongestPalindromicSubstring]")
{
    REQUIRE(LongestPalindromicSubstringManacher().longestPalindrome("babad") == "bab");
    REQUIRE(LongestPalindromicSubstringManacher().longestPalindrome("cbbd") == "bb");
}

