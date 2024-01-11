/*
 * 剑指 Offer 07. 重建二叉树
 */

// @lc code=start

/*
Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include<vector>
using std::vector;

class Solution {
private:
    TreeNode* _buildTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int k, int l)  
    {
        if (i >= j) return nullptr;

        int root_val = preorder[i];
        int root_i = k;
        for (; root_i < l; ++root_i)
        {
            if (inorder[root_i] == root_val) break;
        }
        int left_end = i + 1 + root_i - k;

        TreeNode *root = new TreeNode(root_val);
        root->left = _buildTree(preorder, i + 1, left_end, inorder, k, root_i);
        root->right = _buildTree(preorder, left_end, j, inorder, root_i + 1, l);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end
