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

//Lesson : do not mod too early

class Solution
{
public:
    long res = 0;
    long sum = 0;
    int MOD = 1e9 + 7;

    void findSum(TreeNode *root)
    {
        if (root == NULL)
            return;
        sum += root->val;
        findSum(root->left);
        findSum(root->right);
    }

    long helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        long leftCut = helper(root->left);
        long rightCut = helper(root->right);
        res = max(res, max(((sum - leftCut) * leftCut), ((sum - rightCut) * (rightCut))));
        return (root->val + leftCut + rightCut);
    }

    int maxProduct(TreeNode *root)
    {
        findSum(root);
        helper(root);
        return res % MOD;
    }
};