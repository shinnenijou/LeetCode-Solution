#include "catch_amalgamated.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class NextPermutation {
public:
    void nextPermutation(vector<int>& nums) {
        // find the longest descending suffix
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) --i;

        // reverse it to be ascending
        reverse(nums.begin() + i, nums.end());

        // no previous element
        if (i == 0) return;

        // find the first element greater the previous element then swap it
        int& prev = nums[i - 1];
        for (; i < nums.size() && prev >= nums[i]; ++i) {}
        swap(nums[i], prev);
    }
};

TEST_CASE("NextPermutation", "[NextPermutation]")
{
    vector<int> nums{};

    nums = {1,2,3};
    NextPermutation().nextPermutation(nums);
    REQUIRE(nums == vector<int>{1,3,2});


    nums = {3,2,1};
    NextPermutation().nextPermutation(nums);
    REQUIRE(nums == vector<int>{1,2,3});

    nums = {1,1,5};
    NextPermutation().nextPermutation(nums);
    REQUIRE(nums == vector<int>{1,5,1});

    nums = {1,5,4,3,2};
    NextPermutation().nextPermutation(nums);
    REQUIRE(nums == vector<int>{2,1,3,4,5});
}