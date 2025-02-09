/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool _isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot->val)return false;
        return _isSameTree(root->left, subRoot->left) && 
            _isSameTree(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        bool isSame = false;
        if(root->val == subRoot->val){
            isSame = _isSameTree(root->left, subRoot->left) &&
                _isSameTree(root->right, subRoot->right);
        }
        return isSame || 
            isSubtree(root->left, subRoot) || 
            isSubtree(root->right, subRoot);
    }
};
// @lc code=end

