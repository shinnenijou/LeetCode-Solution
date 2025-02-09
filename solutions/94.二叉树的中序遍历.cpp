/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
    vector<int> m_traversal;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return m_traversal;
        inorderTraversal(root->left);
        m_traversal.push_back(root->val);
        inorderTraversal(root->right);
        return m_traversal;
    }
};
// @lc code=end

