/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
#include<cmath>
class Solution {
private:
    int m_tilt_sum = 0;
    int _getTilt(TreeNode* root){
        if(!root) return 0;
        int left_val_sum = _getTilt(root->left);
        int right_val_sum = _getTilt(root->right);
        m_tilt_sum += std::abs(left_val_sum - right_val_sum);
        return root->val + left_val_sum + right_val_sum;
    }

public:
    int findTilt(TreeNode* root) {
        m_tilt_sum = 0;
        _getTilt(root);
        return m_tilt_sum;
    }
};
// @lc code=end

