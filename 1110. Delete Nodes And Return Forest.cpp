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
    vector<TreeNode *> res;
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (root == NULL)
            return res;
        unordered_set<int> delete_;
        for (auto it : to_delete)
            delete_.insert(it);
        f(root, delete_, true);
        return res;
    }

    TreeNode *f(TreeNode *root, unordered_set<int> delete_, bool isRoot)
    {
        if (root == nullptr)
            return nullptr;
        bool deleted = delete_.find(root->val) != delete_.end();
        if (isRoot && !deleted)
            res.push_back(root);
        root->left = f(root->left, delete_, deleted);
        root->right = f(root->right, delete_, deleted);
        return deleted ? nullptr : root;
    }
};