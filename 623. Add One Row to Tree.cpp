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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (root == NULL)
            return nullptr;
        if (depth == 1)
        {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        int level = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            if (level == depth - 1)
            {
                int sz = q.size();
                while (sz--)
                {
                    TreeNode *frnt = q.front();
                    q.pop();
                    TreeNode *leftchild = frnt->left;
                    TreeNode *rightchild = frnt->right;
                    frnt->left = new TreeNode(val);
                    frnt->right = new TreeNode(val);
                    frnt->right->right = rightchild;
                    frnt->left->left = leftchild;
                }
                break;
            }
            else
            {
                int sz = q.size();
                while (sz--)
                {
                    TreeNode *frnt = q.front();
                    q.pop();
                    if (frnt->left)
                        q.push(frnt->left);
                    if (frnt->right)
                        q.push(frnt->right);
                }
                level++;
            }
        }
        return root;
    }
};