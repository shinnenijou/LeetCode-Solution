/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include<cmath>
#include "TreeNode.h"
class Solution {
private:
    int _min_value = 10000;
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool is_left_balanced = isBalanced(root->left);
        bool is_right_balanced = isBalanced(root->right);
        int left_depth = 0, right_depth = 0;
        if(root->left){
            left_depth = root->left->val & 0x0000FFFF;
            root->left->val = (root->left->val >> 16) - _min_value;
        }
        if(root->right){
            right_depth = root->right->val & 0x0000FFFF;
            root->right->val = (root->right->val >> 16) - _min_value;
        }
        root->val = ((root->val + _min_value) << 16) + (left_depth > right_depth ? left_depth : right_depth) + 1;
        return is_left_balanced && is_right_balanced && std::abs(left_depth - right_depth) <= 1;
    }
};
// @lc code=end

