#include "catch_amalgamated.hpp"
#include <string>

using namespace std;

class ZigzagConversion {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) return s;

        string result(s.size(), '\0');
        int count = 0;

        const int step = (numRows - 1) << 1;

        // first row
        for (int j = 0; j < s.size(); j += step)
        {
            result[count++] = s[j];
        }

        for (int i = 1; i < numRows - 1; ++i)
        {
            const int subStep = (numRows - i - 1) << 1;

            for (int j = i; j < s.size(); j += step)
            {
                result[count++] = s[j];
                if (j + subStep < s.size()) result[count++] = s[j + subStep];
            }
        }

        // last row
        for (int j = numRows - 1; j < s.size(); j += step)
        {
            result[count++] = s[j];
        }

        return result;
    }
};

TEST_CASE("ZigzagConversion", "[ZigzagConversion]")
{
    REQUIRE(ZigzagConversion().convert("PAYPALISHIRING" , 3) == "PAHNAPLSIIGYIR");
    REQUIRE(ZigzagConversion().convert("PAYPALISHIRING" , 4) == "PINALSIGYAHRPI");
    REQUIRE(ZigzagConversion().convert("A" , 1) == "A");
}