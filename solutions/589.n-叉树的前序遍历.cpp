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
#include <vector>
#include <stack>

#include "Node.h"

using std::stack;
using std::vector;
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        stack<int> child_index;
        stack<Node *> parent;
        Node *cur_node = root;

        while (!parent.empty() || ret.empty())
        {
            ret.push_back(cur_node->val);
            if (!cur_node->children.empty())
            {
                parent.push(cur_node);
                child_index.push(0);
                cur_node = cur_node->children.front();
            }
            else
            {
                while (!parent.empty())
                {
                    if (child_index.top() + 1 >= parent.top()->children.size())
                    {
                        child_index.pop();
                        parent.pop();
                    }
                    else
                    {
                        int temp = child_index.top();
                        child_index.pop();
                        child_index.push(temp + 1);
                        cur_node = parent.top()->children[temp + 1];
                        break;
                    }
                }
            }
        }

        return ret;
    }
};
// @lc code=end

