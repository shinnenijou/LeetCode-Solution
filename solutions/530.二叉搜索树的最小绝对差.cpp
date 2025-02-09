/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
#include<climits>
#include "TreeNode.h"
class Solution {
private:
    int m_prev_val = INT_MAX;
    int m_min_diff = INT_MAX;
    void _pre_order_traversal(TreeNode* root){
        if(!root) return;
        _pre_order_traversal(root->left);
        int diff = std::abs(root->val - m_prev_val);
        if(diff < m_min_diff){
            m_min_diff = diff;
        }
        m_prev_val = root->val;
        _pre_order_traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        _pre_order_traversal(root);
        return m_min_diff;
    }
};
// @lc code=end

