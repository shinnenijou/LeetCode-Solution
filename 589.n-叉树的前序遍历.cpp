/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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

class Solution {
private:
    void _preorder(Node *root, vector<int> &ivec)
    {
        if(!root) return;
        ivec.push_back(root->val);
        for(int i = 0; i != root->children.size(); i++){
            _preorder((root->children)[i], ivec);
        }
    }

public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        _preorder(root, ret);
        return ret;
    }
};
// @lc code=end

