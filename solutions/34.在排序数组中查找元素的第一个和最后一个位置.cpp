#include "catch_amalgamated.hpp"
#include <vector>

using namespace std;


class FindFirstAndLastPositionOfElementInSortedArray {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        return searchRange(nums, target, 0, nums.size());
    }
private:
    vector<int> searchRange(const vector<int>& nums, int target, int low, int high)
    {
        if (low >= high) return {-1, -1};

        const int mid = low + ((high - low) >> 1);

        if (nums[mid] < target) return searchRange(nums, target, mid + 1, high);
        if (nums[mid] > target) return searchRange(nums, target, low, mid);
        return {searchLeft(nums, target, low, mid + 1), searchRight(nums, target, mid, high)};
    }

    // search must hit
    int searchLeft(const vector<int>& nums, int target, int low, int high)
    {
        const int mid = low + ((high - low) >> 1);

        if (nums[mid] < target) return searchLeft(nums, target, mid + 1, high);
        if (mid > low && nums[mid - 1] == target) return searchLeft(nums, target, low, mid);

        return mid;
    }

    // search must hit
    int searchRight(const vector<int>& nums, int target, int low, int high)
    {
        const int mid = low + ((high - low ) >> 1);

        if (nums[mid] > target) return searchRight(nums, target, low, mid);
        if (mid + 1 < high && nums[mid + 1] == target) return searchRight(nums, target, mid + 1, high);

        return mid;
    }

};

TEST_CASE("FindFirstAndLastPositionOfElementInSortedArray", "[FindFirstAndLastPositionOfElementInSortedArray]")
{
    using solution = FindFirstAndLastPositionOfElementInSortedArray;

    REQUIRE(solution().searchRange({5,7,7,8,8,10}, 8) == vector<int>{3,4});
    REQUIRE(solution().searchRange({5,7,7,8,8,10}, 6) == vector<int>{-1, -1});
    REQUIRE(solution().searchRange({5,7,7,8,8,10}, 10) == vector<int>{5, 5});
    REQUIRE(solution().searchRange({5,7,7,8,8,10}, 5) == vector<int>{0, 0});
    REQUIRE(solution().searchRange({}, 1) == vector<int>{-1, -1});

}