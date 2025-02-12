#include "catch_amalgamated.hpp"

#include <vector>
#include <algorithm>
using namespace std;

class RotateArray
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if (nums.empty()) return;
        k %= static_cast<int>(nums.size());
        if (k == 0) return;
        moveLeft(nums, 0, nums.size() - k, nums.size());
    }

private:

    // suppose (high - mid) <= (mid - low)
    // then all elements can swap as long as possible
    void moveLeft(vector<int>& nums, const int low, const int mid, const int high)
    {
        if (mid >= high) return;

        int i = mid;
        const int distance = high - mid;

        while (i - distance >= low)
        {
            for (int j = i - distance; j < i; ++j)
            {
                swap(nums[j], nums[j + distance]);
            }

            i -= distance;
        }

        moveRight(nums, low, i, i + distance);
    }

    // suppose (mid - low) <= (high - mid)
    // then all elements can swap as long as possible
    void moveRight(vector<int>& nums, const int low, const int mid, const int high)
    {
        if (low >= mid) return;

        int i = low;
        const int distance = mid - low;

        while (i + distance + distance <= high)
        {
            for (int j = i; j < i + distance; ++j)
            {
                swap(nums[j], nums[j + distance]);
            }

            i += distance;
        }

        moveLeft(nums, i, i + distance, high);
    }
};

class RotateArrayReverse
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if (nums.empty()) return;
        k %= static_cast<int>(nums.size());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


TEST_CASE("RotateArray", "[RotateArray]")
{
    vector<int> nums;

    nums = {1, 2, 3, 4, 5, 6, 7};
    RotateArray().rotate(nums, 3);
    REQUIRE(nums == vector<int>{5, 6, 7, 1, 2, 3, 4});

    nums = {1, 2, 3, 4, 5, 6, 7};
    RotateArray().rotate(nums, 5);
    REQUIRE(nums == vector<int>{3, 4, 5, 6, 7, 1, 2});

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    RotateArray().rotate(nums, 5);
    REQUIRE(nums == vector<int>{ 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}


TEST_CASE("RotateArrayReverse", "[RotateArray]")
{
    vector<int> nums;

    nums = {1, 2, 3, 4, 5, 6, 7};
    RotateArrayReverse().rotate(nums, 3);
    REQUIRE(nums == vector<int>{5, 6, 7, 1, 2, 3, 4});

    nums = {1, 2, 3, 4, 5, 6, 7};
    RotateArrayReverse().rotate(nums, 5);
    REQUIRE(nums == vector<int>{3, 4, 5, 6, 7, 1, 2});

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    RotateArrayReverse().rotate(nums, 5);
    REQUIRE(nums == vector<int>{ 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}