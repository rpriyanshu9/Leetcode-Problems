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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 9 3 15 20 7
        // 9 15 7 20 3
        int n = postorder.size();
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend)
    {
        if (instart > inend || poststart > postend)
            return NULL;
        int rootValue = postorder[postend];
        TreeNode *root = new TreeNode(rootValue);
        int len = 0;
        for (int i = instart; i <= inend; i++)
        {
            if (inorder[i] == rootValue)
                break;
            len++;
        }
        int inorder_left_len = len;
        int inorder_right_len = inend - instart + 1 - (len + 1);
        root->left = helper(inorder, postorder, instart, instart + len - 1, poststart, poststart + len - 1);
        root->right = helper(inorder, postorder, instart + len + 1, inend, poststart + len, poststart + len + inorder_right_len - 1);
        return root;
    }
};