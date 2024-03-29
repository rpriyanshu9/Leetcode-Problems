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

//TLE solution

// class Solution
// {
// public:
//     unordered_map<TreeNode *, TreeNode *> parent;
//     vector<TreeNode *> rootNodes;
//     int res = 0;

//     int countPairs(TreeNode *root, int distance)
//     {
//         findRootNodes(root);
//         findParent(root, NULL);
//         for (auto it : rootNodes)
//         {
//             unordered_map<TreeNode *, bool> vis;
//             dfs(it, 0, distance, vis);
//         }
//         return res / 2;
//     }

//     void findRootNodes(TreeNode *root)
//     {
//         if (root == NULL)
//             return;
//         if (isRoot(root))
//         {
//             rootNodes.push_back(root);
//             return;
//         }
//         findRootNodes(root->left);
//         findRootNodes(root->right);
//     }

//     void findParent(TreeNode *root, TreeNode *par)
//     {
//         if (root == NULL)
//             return;
//         parent[root] = par;
//         findParent(root->left, root);
//         findParent(root->right, root);
//     }

//     bool isRoot(TreeNode *root)
//     {
//         return root->left == NULL && root->right == NULL;
//     }

//     void dfs(TreeNode *root, int steps, int k, unordered_map<TreeNode *, bool> &vis)
//     {
//         if (root == NULL)
//             return;
//         if (steps > 0 && steps <= k && isRoot(root))
//         {
//             res++;
//             return;
//         }
//         vis[root] = true;
//         if (root->left && !vis[root->left])
//         {
//             dfs(root->left, steps + 1, k, vis);
//         }
//         if (root->right && !vis[root->right])
//         {
//             dfs(root->right, steps + 1, k, vis);
//         }
//         if (parent[root] != NULL && !vis[parent[root]])
//         {
//             dfs(parent[root], steps + 1, k, vis);
//         }
//     }
// };

//Accepted
class Solution
{
public:
    int res = 0;
    int countPairs(TreeNode *root, int distance)
    {
        dfs(root, distance);
        return res;
    }

    vector<int> dfs(TreeNode *root, int k)
    {
        vector<int> dist = {};
        if (root == NULL)
            return dist;

        auto leftDist = dfs(root->left, k);
        auto rightDist = dfs(root->right, k);

        if (leftDist.size() == 0 && rightDist.size() == 0)
        {
            dist.push_back(1);
            return dist;
        }
        for (int i = 0; i < leftDist.size(); i++)
        {
            for (int j = 0; j < rightDist.size(); j++)
            {
                if (leftDist[i] + rightDist[j] <= k)
                {
                    res++;
                }
            }
        }
        for (int i = 0; i < leftDist.size(); i++)
        {
            leftDist[i]++;
            dist.push_back(leftDist[i]);
        }

        for (int i = 0; i < rightDist.size(); i++)
        {
            rightDist[i]++;
            dist.push_back(rightDist[i]);
        }

        return dist;
    }
};