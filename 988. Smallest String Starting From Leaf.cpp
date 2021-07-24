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
    unordered_map<int, char> mp;

    void helper(TreeNode *root, string curr, string &res)
    {
        if (!root)
        {
            return;
        }
        curr += mp[root->val];
        if (!root->left && !root->right)
        {
            reverse(curr.begin(), curr.end());
            if (curr < res)
            {
                res = curr;
            }
            return;
        }
        helper(root->left, curr, res);
        helper(root->right, curr, res);
    }

    //because i had it pre written
    void fillMap()
    {
        mp[0] = 'a';
        mp[1] = 'b';
        mp[2] = 'c';
        mp[3] = 'd';
        mp[4] = 'e';
        mp[5] = 'f';
        mp[6] = 'g';
        mp[7] = 'h';
        mp[8] = 'i';
        mp[9] = 'j';
        mp[10] = 'k';
        mp[11] = 'l';
        mp[12] = 'm';
        mp[13] = 'n';
        mp[14] = 'o';
        mp[15] = 'p';
        mp[16] = 'q';
        mp[17] = 'r';
        mp[18] = 's';
        mp[19] = 't';
        mp[20] = 'u';
        mp[21] = 'v';
        mp[22] = 'w';
        mp[23] = 'x';
        mp[24] = 'y';
        mp[25] = 'z';
    }

    string smallestFromLeaf(TreeNode *root)
    {

        fillMap();

        string res = "|";
        string curr = "";
        helper(root, curr, res);
        return res;
    }
};