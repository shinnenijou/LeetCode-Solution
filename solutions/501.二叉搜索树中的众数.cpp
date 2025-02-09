/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

#include<vector>
#include<climits>
#include "TreeNode.h"
class Solution {
private:
    void _pre_order_traversal(TreeNode* root){
        if(!root) return;
        _pre_order_traversal(root->left);
        if(root->val != m_prev_val){
            m_cur_time = 1;
        }
        else{
            m_cur_time++;
        }
        if(m_cur_time == m_mode_time){
            m_mode.push_back(root->val);
        }
        else if(m_cur_time > m_mode_time){
            m_mode_time = m_cur_time;
            m_mode.clear();
            m_mode.push_back(root->val);
        }
        m_prev_val = root->val;
        _pre_order_traversal(root->right);
    }
    std::vector<int> m_mode;
    int m_prev_val = INT_MAX;
    int m_mode_time = INT_MIN;
    int m_cur_time = INT_MIN;
public:
    std::vector<int> findMode(TreeNode* root) {
        _pre_order_traversal(root);
        return m_mode;
    }
};
// @lc code=end

