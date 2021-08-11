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
    unordered_map<int, int> par;
    TreeNode *temp = NULL;
    int findNodes(TreeNode *root, vector<int> &nodes, int x)
    {
        if (root == NULL)
            return 0;
        if (root->val == x)
        {
            temp = root;
        }
        if (root->left != NULL)
            par[root->left->val] = root->val;
        if (root->right != NULL)
            par[root->right->val] = root->val;
        return nodes[root->val] = 1 + findNodes(root->left, nodes, x) + findNodes(root->right, nodes, x);
    }

    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        vector<int> nodes(n + 1, 0);
        par[root->val] = -1;
        findNodes(root, nodes, x);
        int leftNodes = temp->left == NULL ? 0 : nodes[temp->left->val];
        int rightNodes = temp->right == NULL ? 0 : nodes[temp->right->val];
        if (par[x] == -1)
        {
            return (leftNodes > n / 2) || (rightNodes > n / 2);
        }
        return n - nodes[x] > n / 2 || (leftNodes > n / 2) || (rightNodes > n / 2);
    }
};