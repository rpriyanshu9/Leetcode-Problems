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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val < val)
        {
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }
        if (root->val > val)
        {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        return root;
    }
};