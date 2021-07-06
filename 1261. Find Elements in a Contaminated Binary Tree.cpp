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
class FindElements
{
public:
    unordered_set<int> track;

    FindElements(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        root->val = 0;
        track.insert(0);
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                temp->left->val = 2 * temp->val + 1;
                track.insert(2 * temp->val + 1);
                q.push(temp->left);
            }
            if (temp->right)
            {
                temp->right->val = 2 * temp->val + 2;
                track.insert(2 * temp->val + 2);
                q.push(temp->right);
            }
        }
    }

    bool find(int target)
    {
        return track.find(target) != track.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */