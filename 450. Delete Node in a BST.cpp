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
    TreeNode *helper(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            if (!root->right)
            {
                return root->left;
            }
            else
            {
                TreeNode *ans = root->right, *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                temp->left = root->left;
                return ans;
            }
        }
        if (key < root->val)
            root->left = helper(root->left, key);
        else if (key > root->val)
            root->right = helper(root->right, key);
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return helper(root, key);
    }
};