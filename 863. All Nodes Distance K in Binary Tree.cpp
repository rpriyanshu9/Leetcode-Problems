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
    unordered_map<int, TreeNode *> par;
    unordered_map<int, bool> vis;

    vector<int> res;

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (root == NULL)
            return res;
        storeParent(root, NULL);
        queue<TreeNode *> q;
        int level = 0;
        q.push(target);
        while (!q.empty())
        {
            vector<int> tempRes;
            int sz = q.size();
            while (sz > 0)
            {
                TreeNode *frnt = q.front();
                vis[frnt->val] = true;
                q.pop();
                tempRes.push_back(frnt->val);
                if (frnt->left && vis[frnt->left->val] == false)
                {
                    q.push(frnt->left);
                }
                if (frnt->right && vis[frnt->right->val] == false)
                {
                    q.push(frnt->right);
                }
                if (par[frnt->val] != NULL && vis[par[frnt->val]->val] == false)
                {
                    q.push(par[frnt->val]);
                }
                sz--;
            }
            if (level == k)
            {
                res = tempRes;
                break;
            }
            level++;
        }
        return res;
    }

    void storeParent(TreeNode *root, TreeNode *parent)
    {
        if (root == NULL)
            return;
        if (parent == NULL)
        {
            par[root->val] = NULL;
        }
        else
        {
            par[root->val] = parent;
        }
        storeParent(root->left, root);
        storeParent(root->right, root);
    }
};