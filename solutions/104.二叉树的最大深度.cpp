/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        return 1 + (left_max_depth > right_max_depth ? left_max_depth : right_max_depth);
    }
};
// @lc code=end

