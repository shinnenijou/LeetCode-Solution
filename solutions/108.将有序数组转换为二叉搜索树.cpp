/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {
private:
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left >= right) return nullptr;
        int mid = (left + right) >> 1;
        TreeNode* left_child = _sortedArrayToBST(nums, left, mid);
        TreeNode* right_child = _sortedArrayToBST(nums, mid + 1, right);
        TreeNode* root = new TreeNode(nums[mid], left_child, right_child);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }
};
// @lc code=end

