#include "catch_amalgamated.hpp"

#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArrayII {
public:
    int removeDuplicates(vector<int>& nums) {
        int end = 0; // new nums end

        for (int i = 0; i < nums.size();)
        {
            const int value = nums[i];
            int j = searchRight(nums, value, i, nums.size());
            nums[end++] = value;
            if (j - i >= 2) nums[end++] = value;
            i = j;
        }

        return end;
    }

private:
    int searchRight(const vector<int>& nums, const int target, const int left, const int right)
    {
        if (right - left == 1) return right;
        const int mid = left + ((right - left) >> 1);
        if (nums[mid] > target) return searchRight(nums, target, left, mid);
        return searchRight(nums, target, mid, right);
    }
};

TEST_CASE("RemoveDuplicatesFromSortedArrayII", "[RemoveDuplicatesFromSortedArrayII]")
{
    vector<int> nums;

    nums = {1,1,1,2,2,3};
    REQUIRE(RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums) == 5);

    nums = {0,0,1,1,1,1,2,3,3};
    REQUIRE(RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums) == 7);

    nums = {0,0,0,0,0,0};
    REQUIRE(RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums) == 2);

    nums = {};
    REQUIRE(RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums) == 0);

    nums = {1,1,1,2,2,2,3,3};
    REQUIRE(RemoveDuplicatesFromSortedArrayII().removeDuplicates(nums) == 6);
}