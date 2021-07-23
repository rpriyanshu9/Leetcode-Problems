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

    int helper(TreeNode *root, TreeNode *par)
    {
        if (root == NULL)
            return 0;
        int l = helper(root->left, root);
        int r = helper(root->right, root);
        res = max(res, l + r);
        if (par == NULL)
            return 0;
        if (max(l, r) > 0 && root->val == par->val)
            return max(l, r) + 1;
        return root->val == par->val;
    }

    int longestUnivaluePath(TreeNode *root)
    {
        helper(root, NULL);
        return res;
    }
};