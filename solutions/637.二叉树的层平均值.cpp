/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
#include<queue>
#include "TreeNode.h"

using std::vector;
using std::queue;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root) return ret;
        int cur_level_node = 1, count = 0, next_level_node = 0;
        double level_sum = 0;
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            TreeNode *cur_node = node_queue.front();
            node_queue.pop();

            if(cur_node->left){
                node_queue.push(cur_node->left);
                next_level_node++;
            }

            if(cur_node->right){
                node_queue.push(cur_node->right);
                next_level_node++;
            }

            level_sum += cur_node->val;
            count++;

            if(count == cur_level_node){
                ret.push_back(level_sum / cur_level_node);
                count = 0;
                cur_level_node = next_level_node;
                next_level_node = 0;
                level_sum = 0;
            }
        }

        return ret;
    }
};
// @lc code=end

