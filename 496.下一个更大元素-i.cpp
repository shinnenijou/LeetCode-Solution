/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include<vector>
// @lc code=start
class Solution {
private:
    int _find_next_greater_element(std::vector<int>::iterator first, std::vector<int>::iterator last, int value){
        for(; first != last; first++)
            if(*first > value) return *first;
        return -1;
    }
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ret;
        for(int i = 0; i != nums1.size(); i++){
            auto iter = std::find(nums2.begin(), nums2.end(), nums1[i]);
            ret.push_back(_find_next_greater_element(iter, nums2.end(), nums1[i]));
        }
        return ret;
    }
};
// @lc code=end

