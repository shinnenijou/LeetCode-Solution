/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "TreeNode.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return root;
        }

        TreeNode *cur_node = root;

        while(1){
            if(cur_node->val < p->val && cur_node->val < q->val){
                cur_node = cur_node->right;
            }
            else if(cur_node->val > p->val && cur_node->val > q->val){
                cur_node = cur_node->left;
            }
            else{
                return cur_node;
            }
        }
    }
};
// @lc code=end

