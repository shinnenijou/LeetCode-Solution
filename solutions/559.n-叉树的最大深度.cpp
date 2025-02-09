/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include "Node.h"

class Solution {
private:
    int _maxDepth(Node* root){
        int max_depth = 0;
        for(auto iter = root->children.begin(); iter != root->children.end(); iter++){
            int children_depth = _maxDepth(*iter);
            max_depth = children_depth > max_depth?children_depth:max_depth;
        }
        return max_depth + 1;
    }
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        return _maxDepth(root);
    }
};
// @lc code=end

