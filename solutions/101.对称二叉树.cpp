/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
private:
    bool _isSymmetric(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val
               && _isSymmetric(p->left, q->right)
               && _isSymmetric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return _isSymmetric(root->left, root->right);
    }
};
// @lc code=end

