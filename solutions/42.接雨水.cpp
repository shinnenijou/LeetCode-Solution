#include "catch_amalgamated.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class TrappingRainWater
{
    static int water(const vector<int>& height, const int left, const int right)
    {
        int ret = 0;
        const int horizon = min(height[left], height[right]);

        for (int i = left + 1; i < right; ++i)
        {
            ret += max(horizon - height[i], 0);
        }

        return ret;
    }

    static int get_height(const vector<int>& height, int i)
    {
        return i >= 0 && i < static_cast<int>(height.size()) ? height[i] : 0;
    }

public:
    int trap(const vector<int>& height)
    {
        vector<int> peeks;
        int peek = -1;

        for (int i = 0; i < static_cast<int>(height.size()) + 1; ++i)
        {
            if (get_height(height, i) >= get_height(height, i - 1))
            {
                peek = i;
            }
            else if (peek >= 0) /* height[i] < height[i - 1] */
            {
                while (peeks.size() > 1)
                {
                    if (height[peeks.back()] <= height[peek] && height[peeks.back()] <= height[peeks[peeks.size() - 2]])
                    {
                        peeks.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }

                peeks.push_back(peek);
                peek = -1;
            }
        }

        for (auto i : peeks)
        {
            cout << i << ' ';
        }

        cout << endl;

        int result = 0;

        for (size_t i = 1; i < peeks.size(); ++i)
        {
            result += water(height, peeks[i - 1], peeks[i]);
        }

        return result;
    }
};

TEST_CASE("TrappingRainWater", "[TrappingRainWater]")
{
    REQUIRE(TrappingRainWater().trap({}) == 0);
    REQUIRE(TrappingRainWater().trap({0,1,0,2,1,0,1,3,2,1,2,1}) == 6);
    REQUIRE(TrappingRainWater().trap({4,2,0,3,2,5}) == 9);
    REQUIRE(TrappingRainWater().trap({6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3}) == 83);
}
