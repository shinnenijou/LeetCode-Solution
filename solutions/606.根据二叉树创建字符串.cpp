/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
#include <string>
#include "TreeNode.h"
using namespace std;
class Solution
{
private:
    void _tree2str(TreeNode *root, string &str)
    {
        if (!root)
            return;
        str += std::to_string(root->val);
        if (root->left || root->right)
        {
            str += '(';
            _tree2str(root->left, str);
            str += ')';
            if (root->right)
            {
                str += '(';
                _tree2str(root->right, str);
                str += ')';
            }
        }
    }

public:
    string tree2str(TreeNode *root)
    {
        string ret;
        _tree2str(root, ret);
        return ret;
    }
};
// @lc code=end
