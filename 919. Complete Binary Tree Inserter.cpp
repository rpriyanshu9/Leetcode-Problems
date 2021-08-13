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
class CBTInserter
{
public:
    TreeNode *rootOfTree, temp;
    queue<TreeNode *> q;

    CBTInserter(TreeNode *root)
    {
        rootOfTree = root;
        queue<TreeNode *> temp_q;
        temp_q.push(root);
        while (!temp_q.empty())
        {
            TreeNode *frnt = temp_q.front();
            q.push(frnt);
            temp_q.pop();
            if (frnt->left)
            {
                temp_q.push(frnt->left);
            }
            if (frnt->right)
            {
                temp_q.push(frnt->right);
            }
        }
    }

    int insert(int val)
    {
        while ((!q.empty()) && (q.front()->left != NULL && q.front()->right != NULL))
            q.pop();
        if (!q.empty())
        {
            TreeNode *front = q.front();
            if (front->left == NULL)
            {
                front->left = new TreeNode(val);
                q.push(front->left);
            }
            else if (front->right == NULL)
            {
                front->right = new TreeNode(val);
                q.push(front->right);
            }
            if (front->left != NULL && front->right != NULL)
            {
                q.pop();
            }
            return front->val;
        }
        return -1;
    }

    TreeNode *get_root()
    {
        return rootOfTree;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */