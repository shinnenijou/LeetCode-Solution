/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
#include <vector>
using std::vector;
class Solution{ 
    void _inorder(TreeNode *root, vector<int> &ivec){
        if(!root) return;
        _inorder(root->left, ivec);
        ivec.push_back(root->val);
        _inorder(root->right, ivec);
    }
public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder_seq;
        _inorder(root, inorder_seq);
        int i = 0, j = inorder_seq.size() - 1;
        while(i < j){
            int sum = inorder_seq[i] + inorder_seq[j];
            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
};
// @lc code=end
