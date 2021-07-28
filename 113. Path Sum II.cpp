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
    vector<vector<int>> res;

    void helper(TreeNode *root, int remSum, vector<int> poss_ans)
    {
        if (root == NULL)
            return;
        if (!root->left && !root->right)
        {
            remSum -= root->val;
            if (remSum == 0)
            {
                poss_ans.push_back(root->val);
                res.push_back(poss_ans);
            }
            return;
        }
        poss_ans.push_back(root->val);
        helper(root->left, remSum - root->val, poss_ans);
        helper(root->right, remSum - root->val, poss_ans);
        poss_ans.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return res;
        helper(root, targetSum, {});
        return res;
    }
};