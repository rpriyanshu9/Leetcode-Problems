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
    bool helper(TreeNode *root)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        bool leftRes = helper(root->left);
        bool rightRes = helper(root->right);
        if (!leftRes)
            root->left = NULL;
        if (!rightRes)
            root->right = NULL;
        if (leftRes || rightRes)
        {
            return true;
        }
        else
        {
            return root->val;
        }
    }

    TreeNode *pruneTree(TreeNode *root)
    {
        bool res = helper(root);
        return res ? root : NULL;
    }
};