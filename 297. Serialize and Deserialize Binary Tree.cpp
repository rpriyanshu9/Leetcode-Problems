/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *frnt = q.front();
            q.pop();
            if (frnt != nullptr)
                res += to_string(frnt->val);
            else
                res += "null";
            res += ",";
            if (frnt != NULL)
            {
                q.push(frnt->left);
                q.push(frnt->right);
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        vector<TreeNode *> values;
        for (int i = 0; i < data.length();)
        {
            int j = i;
            while (j < data.length() && data[j] != ',')
                j++;
            j--;
            int len = j - i + 1;
            TreeNode *nn;
            if (data.substr(i, len) == "null")
            {
                nn = NULL;
            }
            else
                nn = new TreeNode(stoi(data.substr(i, len)));
            values.push_back(nn);
            i = j + 2;
        }
        TreeNode *root = values[0];
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 1;
        for (int i = 1; i < values.size(); i++)
        {
            if (!q.empty())
            {
                if (cnt == 1)
                {
                    q.front()->left = values[i];
                    if (values[i] != NULL)
                        q.push(values[i]);
                    cnt--;
                    continue;
                }
                if (cnt == 0)
                {
                    q.front()->right = values[i];
                    if (values[i] != NULL)
                        q.push(values[i]);
                    q.pop();
                    cnt = 1;
                    continue;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));