/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root || !root->left) return -1;
        if(root->left->val == root->right->val){
            int left_second_min = findSecondMinimumValue(root->left);
            int right_second_min = findSecondMinimumValue(root->right);
            if(left_second_min != -1 && right_second_min != -1){
                return left_second_min < right_second_min ? left_second_min : right_second_min;
            }
            else{
                return left_second_min > right_second_min ? left_second_min : right_second_min;
            }
        }
        else{
            TreeNode *less = root->left->val < root->right->val ? root->left : root->right;
            TreeNode *greater = root->left->val < root->right->val ? root->right : root->left;
            int less_second_min = findSecondMinimumValue(less);
            if(less_second_min != -1){
                return less_second_min < greater->val ? less_second_min : greater->val;
            }
            else{
                return greater->val;
            }
        }

        return -1;
    }
};
// @lc code=end

