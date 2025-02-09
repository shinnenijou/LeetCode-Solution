//
// Created by YuxinLiu on 2025/2/9.
//

#ifndef TREENODE_H
#define TREENODE_H

/**
 * Definition for a binary tree node.
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#endif //TREENODE_H
