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
class Solution
{
public:
    int res = 0;

    int longestZigZag(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        res = max(res, max(helper(root->left, true, 1), helper(root->right, false, 1)));
        return res;
    }

    int helper(TreeNode *root, bool left, int nodes)
    {
        if (root == NULL)
            return nodes - 1;
        int leftDirection = helper(root->left, true, 1);
        int rightDirection = helper(root->right, false, 1);
        res = max(res, max(rightDirection, leftDirection));
        if (left)
        {
            return rightDirection + nodes;
        }
        else
        {
            return leftDirection + nodes;
        }
    }
};