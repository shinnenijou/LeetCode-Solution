#include "catch_amalgamated.hpp"
#include <string>
#include <limits>

using namespace std;


class StringToIntegerAtoi
{
public:
    int myAtoi(const string& s)
    {
        int index = 0;
        int integer = 0;

        // skip prefix space
        while (index < s.size() && s[index] == ' ') ++index;

        // sign
        if (index == s.size() || !isLeagal(s[index])) return 0;
        const bool sign = s[index] != '-';
        index = isNumber(s[index]) ? index : index + 1;

        // skip prefix 0
        while (index < s.size() && s[index] == '0') ++index;

        if (sign)
        {
            for (; index < s.size() && isNumber(s[index]); ++index)
            {
                const int digit = s[index] - '0';

                // overflow
                if (integer > UPPER_BOUND || integer * 10 > INT_MAX - digit)
                {
                    integer = INT_MAX;
                    break;
                }

                integer = integer * 10 + digit;
            }
        }
        else
        {
            for (; index < s.size() && isNumber(s[index]); ++index)
            {
                const int digit = s[index] - '0';

                // overflow
                if (integer < LOWER_BOUND || integer * 10 < INT_MIN + digit)
                {
                    integer = INT_MIN;
                    break;
                }

                integer = integer * 10 - digit;
            }
        }

        return integer;
    }

private:
    static constexpr int UPPER_BOUND = INT_MAX / 10;
    static constexpr int LOWER_BOUND = INT_MIN / 10;

    static bool isNumber(const char ch) { return ch >= '0' && ch <= '9'; }
    static bool isLeagal(const char ch) { return isNumber(ch) || ch == '-' || ch == '+'; }
};

TEST_CASE("StringToIntegerAtoi", "[StringToIntegerAtoi]")
{
    REQUIRE(StringToIntegerAtoi().myAtoi("42") == 42);
    REQUIRE(StringToIntegerAtoi().myAtoi("   ") == 0);
    REQUIRE(StringToIntegerAtoi().myAtoi(" -042") == -42);
    REQUIRE(StringToIntegerAtoi().myAtoi("1337c0d3") == 1337);
    REQUIRE(StringToIntegerAtoi().myAtoi("0-1") == 0);
    REQUIRE(StringToIntegerAtoi().myAtoi("words and 987") == 0);
    REQUIRE(StringToIntegerAtoi().myAtoi("123456789123456789") == INT_MAX);
    REQUIRE(StringToIntegerAtoi().myAtoi("-123456789123456789") == INT_MIN);
}