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
    unordered_map<string, int> setOfST;
    vector<TreeNode *> res;

    string getAllSubtrees(TreeNode *root)
    {
        if (root == NULL)
            return "x";
        string temp = to_string(root->val) + "|" + getAllSubtrees(root->left) + "|" + getAllSubtrees(root->right);
        if (++setOfST[temp] == 2)
            res.push_back(root);
        return temp;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        getAllSubtrees(root);
        return res;
    }
};