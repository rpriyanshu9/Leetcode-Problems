/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode *possibleLCAOnLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *possibleLCAOnRight = lowestCommonAncestor(root->right, p, q);
        if (possibleLCAOnLeft != NULL && possibleLCAOnRight != NULL)
            return root;
        return possibleLCAOnLeft == NULL ? possibleLCAOnRight : possibleLCAOnLeft;
    }
};