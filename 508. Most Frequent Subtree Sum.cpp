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
    unordered_map<int, int> ump;
    int imax = -1;

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        helper(root, res);
        for (auto it : ump)
            if (it.second == imax)
                res.push_back(it.first);
        return res;
    }

    int helper(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return 0;
        int leftSum = helper(root->left, res);
        int rightSum = helper(root->right, res);
        int sum = root->val + leftSum + rightSum;
        imax = max(imax, ++ump[sum]);
        return sum;
    }
};