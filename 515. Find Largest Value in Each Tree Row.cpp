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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int imax = INT_MIN;
            int sz = q.size();
            while (sz > 0)
            {
                TreeNode *frnt = q.front();
                q.pop();
                imax = max(imax, frnt->val);
                if (frnt->left)
                    q.push(frnt->left);
                if (frnt->right)
                    q.push(frnt->right);
                sz--;
            }
            res.push_back(imax);
        }
        return res;
    }
};